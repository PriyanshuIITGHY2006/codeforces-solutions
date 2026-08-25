
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int IINF = 1e9;
const ld EPS = 1e-9;
const ld PI = acos((ld)-1);
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define srt(v) sort(all(v))
#define uni(v) \
    srt(v);    \
    (v).erase(unique(all(v)), (v).end())
#define nl cout << "\n"
#define YES cout << "YES\n";
#define NO cout << "NO\n";
ll binpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a, ll mod = MOD) { return binpow(a, mod - 2, mod); }
const int MAXN = 2e5 + 5;
ll fact[MAXN], inv_fact[MAXN];

void precompute_factorials(int n = MAXN - 1)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = binpow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll C(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

ll P(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] % MOD * inv_fact[n - r] % MOD;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ld> dp(n + 1);
    dp[n] = ((ld)(a[n - 1] * (a[n - 1] + 1))) / (a[n - 1] * 2);
    for (int i = n - 1; i >= 1; i--)
    {
        int g = (int)dp[i + 1];
        if (a[i - 1] <= g)
        {
            dp[i] = dp[i + 1];
            continue;
        }
        ld num = (ld)(dp[i + 1] * g) + (((ld)(a[i - 1] * (a[i - 1] + 1))) / 2) - (ld)(g * (g + 1)) / 2;
        dp[i] = (ld)(num) / a[i - 1];
        // dp[i] = max(dp[i], dp[i+1]);
    }
    cout << fixed << setprecision(12);
    cout << dp[1];
    // for (auto it : dp)
    //     cout << it << " ";
}

signed main()
{
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}