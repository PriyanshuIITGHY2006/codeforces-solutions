#!/usr/bin/env python3
"""
Codeforces AC Submission Archiver

- Fetches all AC C++ submissions via CF API (metadata only, no scraping)
- Creates organized folders: README.md with rating, tags, links
- If a matching .cpp exists in solutions/ folder, uses it as solution.cpp
- Otherwise writes a placeholder with submission link
"""

import os
import re
import json
import time
import hashlib
import random
import string
import requests
from pathlib import Path

CF_HANDLE = os.environ.get("CF_HANDLE", "PriyanshuIITGHY2006")
CF_API_KEY = os.environ.get("CF_API_KEY", "")
CF_API_SECRET = os.environ.get("CF_API_SECRET", "")
REPO_ROOT = Path(os.environ.get("REPO_ROOT", "."))
SOLUTIONS_DIR = REPO_ROOT / "solutions"
PROBLEMS_DIR = REPO_ROOT / "problems"
LANG_FILTER = "C++"


def cf_api_request(method, params):
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
        raise RuntimeError(f"CF API error: {data.get('comment')}")
    return data["result"]


def get_ac_submissions():
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
        key = f"{prob.get('contestId', 0)}{prob.get('index', '')}"
        if key in seen:
            continue
        seen.add(key)
        result.append(s)
    return result


def sanitize(name):
    return re.sub(r'[^\w\-. ]', '', name).strip().replace(' ', '-')


def rating_bucket(rating):
    if rating is None:
        return "Unrated"
    if rating <= 800:
        return "0800"
    return str(rating)


def load_user_solutions():
    """Load all .cpp files from solutions/ folder, keyed by problem ID."""
    SOLUTIONS_DIR.mkdir(exist_ok=True)
    user_code = {}
    for f in SOLUTIONS_DIR.glob("*.cpp"):
        m = re.match(r'^(\d+[A-Za-z]\d*)', f.name)
        if m:
            user_code[m.group(1)] = f.read_text(encoding="utf-8", errors="replace")
    return user_code


def write_problem(sub, user_code):
    prob = sub["problem"]
    contest_id = prob.get("contestId", 0)
    index = prob.get("index", "")
    name = prob.get("name", "Unknown")
    rating = prob.get("rating")
    tags = prob.get("tags", [])
    key = f"{contest_id}{index}"

    folder_name = f"{contest_id}{index}-{sanitize(name)}"
    prob_dir = PROBLEMS_DIR / rating_bucket(rating) / folder_name
    prob_dir.mkdir(parents=True, exist_ok=True)

    # README.md
    lines = [
        f"# {contest_id}{index} - {name}\n",
        f"**Contest:** [{contest_id}](https://codeforces.com/contest/{contest_id})\n",
        f"**Problem:** [{index}](https://codeforces.com/contest/{contest_id}/problem/{index})\n",
        f"**Rating:** {rating if rating else 'Unrated'}\n",
        f"**Tags:** {', '.join(f'`{t}`' for t in tags) if tags else 'None'}\n",
        f"**Language:** {sub.get('programmingLanguage', 'C++')}\n",
        f"**Submission:** [Link](https://codeforces.com/contest/{contest_id}/submission/{sub['id']})\n",
    ]
    (prob_dir / "README.md").write_text("\n".join(lines), encoding="utf-8")

    # solution.cpp — use user's code if available, otherwise placeholder
    code = user_code.get(key)
    if code:
        (prob_dir / "solution.cpp").write_text(code, encoding="utf-8")
    else:
        placeholder = (
            f"// Problem: {contest_id}{index} - {name}\n"
            f"// Submission: https://codeforces.com/contest/{contest_id}/submission/{sub['id']}\n"
            f"//\n"
            f"// Drop {key}.cpp into the solutions/ folder and push to add your code here.\n"
        )
        # Don't overwrite if user code was there before
        sol_path = prob_dir / "solution.cpp"
        if not sol_path.exists() or sol_path.read_text().startswith("// Problem:"):
            sol_path.write_text(placeholder, encoding="utf-8")


def generate_index(all_subs, user_code):
    total = len(all_subs)
    with_code = sum(1 for s in all_subs
                    if f"{s['problem'].get('contestId',0)}{s['problem'].get('index','')}" in user_code)

    lines = [
        f"# Codeforces Solutions Archive\n",
        f"**Handle:** [{CF_HANDLE}](https://codeforces.com/profile/{CF_HANDLE})\n",
        f"**Language:** C++\n",
        f"**Total Problems:** {total}\n",
        f"**With Source Code:** {with_code} / {total}\n",
        "",
        "## Problems\n",
        "| # | Problem | Rating | Tags | Code | Link |",
        "|---|---------|--------|------|------|------|",
    ]

    sorted_subs = sorted(all_subs, key=lambda s: (s["problem"].get("rating") or 0, s["problem"].get("contestId", 0)))
    for s in sorted_subs:
        p = s["problem"]
        cid = p.get("contestId", 0)
        idx = p.get("index", "")
        name = p.get("name", "?")
        rating = p.get("rating") or "?"
        tags = ", ".join(f"`{t}`" for t in p.get("tags", []))
        key = f"{cid}{idx}"
        has_code = "Yes" if key in user_code else "-"
        folder = f"{cid}{idx}-{sanitize(name)}"
        r_bucket = rating_bucket(p.get("rating"))
        rel_path = f"problems/{r_bucket}/{folder}"
        lines.append(
            f"| {cid}{idx} | [{name}]({rel_path}) | {rating} | {tags} | {has_code} | "
            f"[CF](https://codeforces.com/contest/{cid}/problem/{idx}) |"
        )

    # Tag distribution
    tag_count = {}
    for s in all_subs:
        for t in s["problem"].get("tags", []):
            tag_count[t] = tag_count.get(t, 0) + 1
    lines.append("\n## Tag Distribution\n")
    lines.append("| Tag | Count |")
    lines.append("|-----|-------|")
    for tag, count in sorted(tag_count.items(), key=lambda x: -x[1]):
        lines.append(f"| `{tag}` | {count} |")

    # Rating distribution
    rating_count = {}
    for s in all_subs:
        r = rating_bucket(s["problem"].get("rating"))
        rating_count[r] = rating_count.get(r, 0) + 1
    lines.append("\n## Rating Distribution\n")
    lines.append("| Rating | Count |")
    lines.append("|--------|-------|")
    for r, count in sorted(rating_count.items()):
        lines.append(f"| {r} | {count} |")

    (REPO_ROOT / "README.md").write_text("\n".join(lines), encoding="utf-8")


def main():
    print(f"Fetching AC submissions for {CF_HANDLE}...")
    subs = get_ac_submissions()
    print(f"Found {len(subs)} unique AC C++ submissions.")

    print("Loading user solutions from solutions/ folder...")
    user_code = load_user_solutions()
    print(f"Found {len(user_code)} user-provided .cpp files.")

    for i, sub in enumerate(subs, 1):
        prob = sub["problem"]
        key = f"{prob.get('contestId',0)}{prob.get('index','')}"
        tag = " [CODE]" if key in user_code else ""
        print(f"  [{i}/{len(subs)}] {key} - {prob.get('name','?')}{tag}")
        write_problem(sub, user_code)

    generate_index(subs, user_code)
    print(f"\nDone. {len(user_code)} problems have source code, {len(subs) - len(user_code)} are metadata only.")


if __name__ == "__main__":
    main()
