# Codeforces Submissions Archive

Automatically fetches and archives all accepted C++ submissions from Codeforces using GitHub Actions. Runs every 6 hours with zero manual intervention.

## Repo Structure

```
problems/
  0800/                          # Grouped by rating
    71A-Way-Too-Long-Words/
      README.md                  # Problem statement, rating, tags, links
      solution.cpp               # Your solution
      tests/
        input_1.txt
        output_1.txt
  1200/
    ...
  1600/
    ...
README.md                       # Auto-generated index with all problems, tag/rating stats
fetch.py                        # The sync script
.tracked_submissions.json       # Tracks already-archived submissions
.github/workflows/sync.yml      # Cron workflow
```

## Setup

1. **Create a new GitHub repo** (e.g. `codeforces-solutions`).

2. **Copy all files from this project** into the repo root.

3. **Push to GitHub.**

4. **Enable Actions:** Go to the repo on GitHub → Actions tab → Enable workflows.

5. **First run:** Click Actions → "Sync Codeforces Submissions" → "Run workflow" to trigger immediately.

That is it. The workflow will run every 6 hours automatically and commit any new AC submissions.

## Optional: Include Actual Source Code

By default, the Codeforces API (`user.status`) does **not** return submission source code. To include your actual code:

1. Go to [Codeforces API keys](https://codeforces.com/settings/api) and generate a key+secret.
2. In your GitHub repo, go to **Settings → Secrets and variables → Actions**.
3. Add two secrets:
   - `CF_API_KEY` — your API key
   - `CF_API_SECRET` — your API secret
4. Uncomment the two env lines in `.github/workflows/sync.yml`:
   ```yaml
   CF_API_KEY: ${{ secrets.CF_API_KEY }}
   CF_API_SECRET: ${{ secrets.CF_API_SECRET }}
   ```

> **Note:** Even with API keys, `user.status` does not return source code. For full source code archival, consider using the Codeforces `/submission/{id}` page scraping approach (not included here to respect CF rate limits). The placeholder `solution.cpp` files contain metadata and direct links to the submission.

## Customization

- **Change schedule:** Edit the `cron` line in `.github/workflows/sync.yml`. Use [crontab.guru](https://crontab.guru/) for reference.
- **Change handle:** Update `CF_HANDLE` in the workflow env.
- **Track other languages:** Modify `LANG_FILTER` in `fetch.py`.
