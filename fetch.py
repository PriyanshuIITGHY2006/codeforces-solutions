#!/usr/bin/env python3
"""
Codeforces AC Submission Archiver
Uses curl_cffi to impersonate a real browser TLS fingerprint,
bypassing Cloudflare protection on codeforces.com.
"""

import os
import re
import json
import time
import hashlib
import random
import string
from pathlib import Path
from html.parser import HTMLParser
from curl_cffi import requests as cffi_requests
import requests  # for API calls (no CF protection on API)

# ── Config ──────────────────────────────────────────────────────────────────
CF_HANDLE = os.environ.get("CF_HANDLE", "PriyanshuIITGHY2006")
CF_API_KEY = os.environ.get("CF_API_KEY", "")
CF_API_SECRET = os.environ.get("CF_API_SECRET", "")
REPO_ROOT = Path(os.environ.get("REPO_ROOT", "."))
PROBLEMS_DIR = REPO_ROOT / "problems"
TRACKER_FILE = REPO_ROOT / ".tracked_submissions.json"
LANG_FILTER = "C++"
REQUEST_DELAY = 3
MAX_SCRAPE_FAILURES = 30

# ── Browser-impersonating session ───────────────────────────────────────────
_session = cffi_requests.Session(impersonate="chrome")


def fetch_page(url: str, retries: int = 3) -> str | None:
    """Fetch a page using browser-impersonating TLS."""
    for attempt in range(retries):
        try:
            resp = _session.get(url, timeout=30)
            if resp.status_code == 200:
                return resp.text
            if resp.status_code == 429:
                wait = 10 * (attempt + 1)
                print(f"    [RATE-LIMITED] Waiting {wait}s...")
                time.sleep(wait)
                continue
            print(f"    [HTTP {resp.status_code}] attempt {attempt+1}/{retries}")
        except Exception as e:
            print(f"    [Error] attempt {attempt+1}/{retries}: {e}")
        time.sleep(3 * (attempt + 1))
    return None


# ── HTML to text ────────────────────────────────────────────────────────────
class HTMLToText(HTMLParser):
    def __init__(self):
        super().__init__()
        self._parts = []

    def handle_starttag(self, tag, attrs):
        if tag in ("p", "br", "div", "li"):
            self._parts.append("\n")
        if tag == "pre":
            self._parts.append("\n```\n")
        if tag == "li":
            self._parts.append("- ")
        if tag in ("b", "strong"):
            self._parts.append("**")
        if tag in ("i", "em"):
            self._parts.append("*")

    def handle_endtag(self, tag):
        if tag == "pre":
            self._parts.append("\n```\n")
        if tag in ("b", "strong"):
            self._parts.append("**")
        if tag in ("i", "em"):
            self._parts.append("*")

    def handle_data(self, data):
        self._parts.append(data)

    def get_text(self):
        return "".join(self._parts).strip()


def html_to_text(html: str) -> str:
    parser = HTMLToText()
    parser.feed(html)
    return parser.get_text()


# ── Codeforces API ──────────────────────────────────────────────────────────
def cf_api_request(method: str, params: dict) -> dict:
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
            continue
        seen.add(key)
        result.append(s)
    return result


# ── Source code scraper ─────────────────────────────────────────────────────
def scrape_source_code(contest_id: int, submission_id: int) -> str | None:
    url = f"https://codeforces.com/contest/{contest_id}/submission/{submission_id}"
    html = fetch_page(url)
    if not html:
        return None

    # Try <pre id="program-source-text">
    m = re.search(r'<pre\s+id="program-source-text"[^>]*>(.*?)</pre>', html, re.DOTALL)
    if not m:
        # Alternative: source might be in a different container
        m = re.search(r'id="program-source-text"[^>]*>(.*?)</pre>', html, re.DOTALL)
    if m:
        code = m.group(1)
        code = code.replace("&lt;", "<").replace("&gt;", ">")
        code = code.replace("&amp;", "&").replace("&quot;", '"')
        code = code.replace("&#39;", "'").replace("&nbsp;", " ")
        code = code.replace("&#x27;", "'")
        code = re.sub(r'<br\s*/?>', '\n', code)
        code = re.sub(r'<[^>]+>', '', code)
        return code.strip()

    # Debug: check if we got a CF page or a Cloudflare block
    if "Codeforces" in html and "source" not in html.lower():
        print(f"    [DEBUG] Got CF page but no source code visible (login required?)")
    elif "Cloudflare" in html or "cf-browser-verification" in html:
        print(f"    [DEBUG] Cloudflare challenge page received")
    
    return None


# ── Problem page scraper ────────────────────────────────────────────────────
def scrape_problem(contest_id: int, index: str) -> dict:
    url = f"https://codeforces.com/contest/{contest_id}/problem/{index}"
    html = fetch_page(url)
    if not html:
        return {"statement": "", "inputs": [], "outputs": []}

    statement = ""
    m = re.search(
        r'<div class="problem-statement">(.*?)</div>\s*</div>\s*</div>\s*</div>',
        html, re.DOTALL
    )
    if not m:
        m = re.search(r'<div class="problem-statement">(.*)', html, re.DOTALL)
    if m:
        raw = m.group(1)
        cut = re.split(r'<div class="sample-test">', raw, maxsplit=1)
        statement = html_to_text(cut[0])

    inputs = re.findall(
        r'<div class="input">\s*<div class="title">.*?</div>\s*<pre[^>]*>(.*?)</pre>',
        html, re.DOTALL
    )
    outputs = re.findall(
        r'<div class="output">\s*<div class="title">.*?</div>\s*<pre[^>]*>(.*?)</pre>',
        html, re.DOTALL
    )

    def clean_pre(text: str) -> str:
        text = re.sub(r'<br\s*/?>', '\n', text)
        text = re.sub(r'<[^>]+>', '', text)
        return text.strip()

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


def write_problem(sub: dict, scrape: dict, source_code: str | None):
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

    (prob_dir / "README.md").write_text("\n".join(lines), encoding="utf-8")

    if source_code:
        sol_content = source_code
    else:
        sol_content = (
            f"// Problem: {contest_id}{index} - {name}\n"
            f"// Submission ID: {sub['id']}\n"
            f"// Link: https://codeforces.com/contest/{contest_id}/submission/{sub['id']}\n"
            f"//\n"
            f"// Source code could not be fetched. Visit the link above.\n"
        )
    (prob_dir / "solution.cpp").write_text(sol_content, encoding="utf-8")

    if scrape["inputs"] or scrape["outputs"]:
        test_dir = prob_dir / "tests"
        test_dir.mkdir(exist_ok=True)
        for i, inp in enumerate(scrape["inputs"], 1):
            (test_dir / f"input_{i}.txt").write_text(inp + "\n", encoding="utf-8")
        for i, out in enumerate(scrape["outputs"], 1):
            (test_dir / f"output_{i}.txt").write_text(out + "\n", encoding="utf-8")


# ── Tracker ─────────────────────────────────────────────────────────────────
def load_tracker() -> set:
    if TRACKER_FILE.exists():
        return set(json.loads(TRACKER_FILE.read_text()))
    return set()


def save_tracker(tracked: set):
    TRACKER_FILE.write_text(json.dumps(sorted(tracked)), encoding="utf-8")


# ── Index generator ─────────────────────────────────────────────────────────
def generate_index(all_subs: list[dict]):
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

    tag_count: dict[str, int] = {}
    for s in all_subs:
        for t in s["problem"].get("tags", []):
            tag_count[t] = tag_count.get(t, 0) + 1

    lines.append("\n## Tag Distribution\n")
    lines.append("| Tag | Count |")
    lines.append("|-----|-------|")
    for tag, count in sorted(tag_count.items(), key=lambda x: -x[1]):
        lines.append(f"| `{tag}` | {count} |")

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

    if not new_subs:
        generate_index(subs)
        print("Done.")
        return

    # Test scraping with first submission before committing to all 227
    test_sub = new_subs[0]
    test_cid = test_sub["problem"].get("contestId", 0)
    test_sid = test_sub["id"]
    print(f"\n  Testing scrape on submission {test_sid}...")
    test_code = scrape_source_code(test_cid, test_sid)
    if test_code:
        print(f"  Scraping works! Got {len(test_code)} chars.\n")
    else:
        print(f"  Scraping test failed. Will attempt all but expect metadata-only fallback.\n")

    consecutive_failures = 0
    code_success = 0
    code_fail = 0

    for i, sub in enumerate(new_subs, 1):
        prob = sub["problem"]
        cid = prob.get("contestId", 0)
        idx = prob.get("index", "")
        name = prob.get("name", "?")
        print(f"  [{i}/{len(new_subs)}] {cid}{idx} - {name}")

        # Scrape source code
        source_code = scrape_source_code(cid, sub["id"])
        if source_code:
            print(f"    Source: {len(source_code)} chars")
            consecutive_failures = 0
            code_success += 1
        else:
            print(f"    Source: FAILED")
            consecutive_failures += 1
            code_fail += 1

        time.sleep(REQUEST_DELAY)

        # Scrape problem page
        scrape = scrape_problem(cid, idx)
        if scrape["statement"]:
            consecutive_failures = 0

        write_problem(sub, scrape, source_code)
        tracked.add(str(sub["id"]))

        if i % 10 == 0:
            save_tracker(tracked)
            print(f"  --- Progress: {code_success} codes fetched, {code_fail} failed ---")

        if consecutive_failures >= MAX_SCRAPE_FAILURES:
            print(f"\n  [ABORT] {MAX_SCRAPE_FAILURES} consecutive failures.")
            print(f"  Remaining {len(new_subs) - i} problems: metadata only.")
            for j, sub2 in enumerate(new_subs[i:], i + 1):
                p2 = sub2["problem"]
                print(f"  [{j}/{len(new_subs)}] {p2.get('contestId',0)}{p2.get('index','')} (metadata only)")
                write_problem(sub2, {"statement": "", "inputs": [], "outputs": []}, None)
                tracked.add(str(sub2["id"]))
            break

        time.sleep(REQUEST_DELAY)

    save_tracker(tracked)
    generate_index(subs)
    print(f"\nDone. Source code: {code_success} success, {code_fail} failed.")


if __name__ == "__main__":
    main()
