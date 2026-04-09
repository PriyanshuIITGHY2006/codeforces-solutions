#!/usr/bin/env python3
"""
Codeforces AC Submission Archiver
Fetches all accepted C++ submissions for a user, scrapes problem details
(statement, tags, rating, sample tests), and writes them into an organized folder structure.
"""

import os
import re
import json
import time
import hashlib
import hmac
import random
import string
import requests
from pathlib import Path
from html.parser import HTMLParser

# ── Config ──────────────────────────────────────────────────────────────────
CF_HANDLE = os.environ.get("CF_HANDLE", "PriyanshuIITGHY2006")
CF_API_KEY = os.environ.get("CF_API_KEY", "")
CF_API_SECRET = os.environ.get("CF_API_SECRET", "")
REPO_ROOT = Path(os.environ.get("REPO_ROOT", "."))
PROBLEMS_DIR = REPO_ROOT / "problems"
TRACKER_FILE = REPO_ROOT / ".tracked_submissions.json"
LANG_FILTER = "C++"  # only archive C++ submissions
REQUEST_DELAY = 2  # seconds between CF page scrapes


# ── Utility: HTML to Markdown-ish plain text ────────────────────────────────
class HTMLToText(HTMLParser):
    """Minimal HTML-to-text converter for CF problem statements."""

    def __init__(self):
        super().__init__()
        self._parts = []
        self._in_pre = False

    def handle_starttag(self, tag, attrs):
        if tag in ("p", "br", "div", "li"):
            self._parts.append("\n")
        if tag == "pre":
            self._in_pre = True
            self._parts.append("\n```\n")
        if tag == "ul" or tag == "ol":
            self._parts.append("\n")
        if tag == "li":
            self._parts.append("- ")
        if tag in ("b", "strong"):
            self._parts.append("**")
        if tag in ("i", "em"):
            self._parts.append("*")
        if tag == "sup":
            self._parts.append("^(")
        if tag == "sub":
            self._parts.append("_(")

    def handle_endtag(self, tag):
        if tag == "pre":
            self._in_pre = False
            self._parts.append("\n```\n")
        if tag in ("b", "strong"):
            self._parts.append("**")
        if tag in ("i", "em"):
            self._parts.append("*")
        if tag == "sup":
            self._parts.append(")")
        if tag == "sub":
            self._parts.append(")")

    def handle_data(self, data):
        self._parts.append(data)

    def get_text(self):
        return "".join(self._parts).strip()


def html_to_text(html: str) -> str:
    parser = HTMLToText()
    parser.feed(html)
    return parser.get_text()


# ── Codeforces API helpers ──────────────────────────────────────────────────
def cf_api_request(method: str, params: dict) -> dict:
    """Call CF API with optional authorized request (if keys provided)."""
    params = {k: v for k, v in params.items() if v is not None}
    
    if CF_API_KEY and CF_API_SECRET:
        params["apiKey"] = CF_API_KEY
        params["time"] = str(int(time.time()))
        rand = "".join(random.choices(string.ascii_lowercase + string.digits, k=6))
        sorted_params = "&".join(f"{k}={params[k]}" for k in sorted(params))
        sig_str = f"{rand}/{method}?{sorted_params}#{CF_API_SECRET}"
        sig = hashlib.sha512(sig_str.encode()).hexdigest()
        params["apiSig"] = rand + sig

    url = f"https://codeforces.com/api/{method}"
    resp = requests.get(url, params=params, timeout=30)
    resp.raise_for_status()
    data = resp.json()
    if data.get("status") != "OK":
        raise RuntimeError(f"CF API error: {data.get('comment', 'unknown')}")
    return data["result"]


def get_ac_submissions() -> list[dict]:
    """Fetch all AC C++ submissions for the configured handle."""
    subs = cf_api_request("user.status", {"handle": CF_HANDLE, "from": "1", "count": "100000"})
    seen = set()
    result = []
    for s in subs:
        if s.get("verdict") != "OK":
            continue
        lang = s.get("programmingLanguage", "")
        if LANG_FILTER.lower() not in lang.lower():
            continue
        prob = s["problem"]
        key = f"{prob.get('contestId', 0)}-{prob.get('index', '')}"
        if key in seen:
            continue  # keep only first (most recent) AC per problem
        seen.add(key)
        result.append(s)
    return result


# ── Problem page scraper ────────────────────────────────────────────────────
def scrape_problem(contest_id: int, index: str) -> dict:
    """Scrape a CF problem page for statement and sample tests."""
    url = f"https://codeforces.com/problemset/problem/{contest_id}/{index}"
    try:
        resp = requests.get(url, timeout=30, headers={"User-Agent": "CF-Archiver/1.0"})
        resp.raise_for_status()
    except Exception as e:
        print(f"  [WARN] Could not fetch problem page {contest_id}{index}: {e}")
        return {"statement": "", "inputs": [], "outputs": []}

    html = resp.text

    # Extract problem statement
    statement = ""
    m = re.search(
        r'<div class="problem-statement">(.*?)</div>\s*</div>\s*</div>\s*</div>',
        html, re.DOTALL
    )
    if not m:
        m = re.search(r'<div class="problem-statement">(.*)', html, re.DOTALL)
    if m:
        raw = m.group(1)
        # Try to cut before sample tests
        cut = re.split(r'<div class="sample-test">', raw, maxsplit=1)
        statement = html_to_text(cut[0])

    # Extract sample tests
    inputs = re.findall(r'<div class="input">\s*<div class="title">.*?</div>\s*<pre[^>]*>(.*?)</pre>', html, re.DOTALL)
    outputs = re.findall(r'<div class="output">\s*<div class="title">.*?</div>\s*<pre[^>]*>(.*?)</pre>', html, re.DOTALL)

    def clean_pre(text: str) -> str:
        text = re.sub(r'<br\s*/?>', '\n', text)
        text = re.sub(r'<[^>]+>', '', text)
        text = text.strip()
        return text

    return {
        "statement": statement,
        "inputs": [clean_pre(i) for i in inputs],
        "outputs": [clean_pre(o) for o in outputs],
    }


# ── File writers ────────────────────────────────────────────────────────────
def sanitize(name: str) -> str:
    return re.sub(r'[^\w\-. ]', '', name).strip().replace(' ', '-')


def rating_bucket(rating: int | None) -> str:
    if rating is None:
        return "Unrated"
    if rating <= 800:
        return "0800"
    return str(rating)


def write_problem(sub: dict, scrape: dict):
    """Write one problem's folder: README.md, solution.cpp, tests/."""
    prob = sub["problem"]
    contest_id = prob.get("contestId", 0)
    index = prob.get("index", "")
    name = prob.get("name", "Unknown")
    rating = prob.get("rating")
    tags = prob.get("tags", [])

    folder_name = f"{contest_id}{index}-{sanitize(name)}"
    rating_str = rating_bucket(rating)
    prob_dir = PROBLEMS_DIR / rating_str / folder_name
    prob_dir.mkdir(parents=True, exist_ok=True)

    # ── README.md ───────────────────────────────────────────────────────
    lines = [
        f"# {contest_id}{index} - {name}\n",
        f"**Contest:** [{contest_id}](https://codeforces.com/contest/{contest_id})\n",
        f"**Problem:** [{index}](https://codeforces.com/contest/{contest_id}/problem/{index})\n",
        f"**Rating:** {rating if rating else 'Unrated'}\n",
        f"**Tags:** {', '.join(f'`{t}`' for t in tags) if tags else 'None'}\n",
        f"**Language:** {sub.get('programmingLanguage', 'C++')}\n",
        f"**Submission:** [Link](https://codeforces.com/contest/{contest_id}/submission/{sub['id']})\n",
    ]

    if scrape["statement"]:
        lines.append("\n## Problem Statement\n")
        lines.append(scrape["statement"] + "\n")

    readme_path = prob_dir / "README.md"
    readme_path.write_text("\n".join(lines), encoding="utf-8")

    # ── solution.cpp ────────────────────────────────────────────────────
    source = sub.get("source")
    if not source:
        # source is not returned by user.status; we note that
        sol_content = (
            f"// Problem: {contest_id}{index} - {name}\n"
            f"// Submission ID: {sub['id']}\n"
            f"// Link: https://codeforces.com/contest/{contest_id}/submission/{sub['id']}\n"
            f"//\n"
            f"// NOTE: Codeforces API does not return source code via user.status.\n"
            f"// To include actual code, enable CF_API_KEY / CF_API_SECRET (see README).\n"
        )
    else:
        sol_content = source

    (prob_dir / "solution.cpp").write_text(sol_content, encoding="utf-8")

    # ── tests/ ──────────────────────────────────────────────────────────
    if scrape["inputs"] or scrape["outputs"]:
        test_dir = prob_dir / "tests"
        test_dir.mkdir(exist_ok=True)
        for i, inp in enumerate(scrape["inputs"], 1):
            (test_dir / f"input_{i}.txt").write_text(inp + "\n", encoding="utf-8")
        for i, out in enumerate(scrape["outputs"], 1):
            (test_dir / f"output_{i}.txt").write_text(out + "\n", encoding="utf-8")


# ── Tracker (avoid re-processing) ──────────────────────────────────────────
def load_tracker() -> set:
    if TRACKER_FILE.exists():
        return set(json.loads(TRACKER_FILE.read_text()))
    return set()


def save_tracker(tracked: set):
    TRACKER_FILE.write_text(json.dumps(sorted(tracked)), encoding="utf-8")


# ── Index / Table of Contents ───────────────────────────────────────────────
def generate_index(all_subs: list[dict]):
    """Generate a top-level README with a table of all archived problems."""
    lines = [
        f"# Codeforces Solutions Archive\n",
        f"**Handle:** [{CF_HANDLE}](https://codeforces.com/profile/{CF_HANDLE})\n",
        f"**Language:** C++\n",
        f"**Total Problems:** {len(all_subs)}\n",
        "",
        "## Problems\n",
        "| # | Problem | Rating | Tags | Link |",
        "|---|---------|--------|------|------|",
    ]

    sorted_subs = sorted(all_subs, key=lambda s: (s["problem"].get("rating") or 0, s["problem"].get("contestId", 0)))

    for s in sorted_subs:
        p = s["problem"]
        cid = p.get("contestId", 0)
        idx = p.get("index", "")
        name = p.get("name", "?")
        rating = p.get("rating") or "?"
        tags = ", ".join(f"`{t}`" for t in p.get("tags", []))
        folder = f"{cid}{idx}-{sanitize(name)}"
        r_bucket = rating_bucket(p.get("rating"))
        rel_path = f"problems/{r_bucket}/{folder}"
        lines.append(
            f"| {cid}{idx} | [{name}]({rel_path}) | {rating} | {tags} | "
            f"[CF](https://codeforces.com/contest/{cid}/problem/{idx}) |"
        )

    # Tag summary
    tag_count: dict[str, int] = {}
    for s in all_subs:
        for t in s["problem"].get("tags", []):
            tag_count[t] = tag_count.get(t, 0) + 1

    lines.append("\n## Tag Distribution\n")
    lines.append("| Tag | Count |")
    lines.append("|-----|-------|")
    for tag, count in sorted(tag_count.items(), key=lambda x: -x[1]):
        lines.append(f"| `{tag}` | {count} |")

    # Rating summary
    rating_count: dict[str, int] = {}
    for s in all_subs:
        r = rating_bucket(s["problem"].get("rating"))
        rating_count[r] = rating_count.get(r, 0) + 1

    lines.append("\n## Rating Distribution\n")
    lines.append("| Rating | Count |")
    lines.append("|--------|-------|")
    for r, count in sorted(rating_count.items()):
        lines.append(f"| {r} | {count} |")

    (REPO_ROOT / "README.md").write_text("\n".join(lines), encoding="utf-8")


# ── Main ────────────────────────────────────────────────────────────────────
def main():
    print(f"Fetching AC submissions for {CF_HANDLE}...")
    subs = get_ac_submissions()
    print(f"Found {len(subs)} unique AC C++ submissions.")

    tracked = load_tracker()
    new_subs = [s for s in subs if str(s["id"]) not in tracked]
    print(f"New submissions to archive: {len(new_subs)}")

    for i, sub in enumerate(new_subs, 1):
        prob = sub["problem"]
        cid = prob.get("contestId", 0)
        idx = prob.get("index", "")
        name = prob.get("name", "?")
        print(f"  [{i}/{len(new_subs)}] {cid}{idx} - {name}")

        scrape = scrape_problem(cid, idx)
        write_problem(sub, scrape)
        tracked.add(str(sub["id"]))
        time.sleep(REQUEST_DELAY)

    save_tracker(tracked)
    generate_index(subs)
    print("Done.")


if __name__ == "__main__":
    main()
