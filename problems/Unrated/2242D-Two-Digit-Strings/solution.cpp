/*
 * ██████╗ ██████╗ ██╗██╗   ██╗ █████╗ ███╗   ██╗███████╗██╗  ██╗██╗   ██╗
 * ██╔══██╗██╔══██╗██║╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝██║  ██║██║   ██║
 * ██████╔╝██████╔╝██║ ╚████╔╝ ███████║██╔██╗ ██║███████╗███████║██║   ██║
 * ██╔═══╝ ██╔══██╗██║  ╚██╔╝  ██╔══██║██║╚██╗██║╚════██║██╔══██║██║   ██║
 * ██║     ██║  ██║██║   ██║   ██║  ██║██║ ╚████║███████║██║  ██║╚██████╔╝
 * ╚═╝     ╚═╝  ╚═╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝
 */
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifndef ONLINE_JUDGE
#include "C:\msys64\home\priya\cp\templates\debug.hpp"
#else
#define dbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define dbgv(v)
#define dbgvv(vv)
#define dbgm(m)
#define dbgp(p)
#define dbgg(g)
#define dbgg_un(g)
#define dbgf(v)
#define dbg_range(b, e)
#define dbg_if(c, x)
#define dbg_diff(a, b)
#define dbg_assert(c, ...)
#define dbg_time()
#define here()
#define SCOPE(name)
#define TIMER(name)
#define TICK(name)
#define TICKL(name, label)
#define WATCH(type, name, init) type name = init
#define DBG_SEP(label)
#define DBG_BANNER(s)
#endif
#define int long long
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int IINF = 1e9;
const ld EPS = 1e-9;
const ld PI = acos((ld)-1);
#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(a, x) for (auto &a : (x))
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define uni(v) \
    srt(v);    \
    (v).erase(unique(all(v)), (v).end())
#define sm(v) accumulate(all(v), 0LL)
#define mn(v) *min_element(all(v))
#define mx(v) *max_element(all(v))
#define rev(v) reverse(all(v))
#define popcnt(x) __builtin_popcountll(x)
#define lsb(x) ((x) & -(x))
#define nl cout << "\n"
#define rv(v)            \
    for (auto &_x : (v)) \
        cin >> _x;
#define pv(v)                                          \
    {                                                  \
        for (int _i = 0; _i < sz(v); _i++)             \
            cout << (v)[_i] << " \n"[_i + 1 == sz(v)]; \
    }
#define pvn(v)           \
    for (auto &_x : (v)) \
    cout << _x << "\n"
#define pv2(vv)                                        \
    for (auto &_r : (vv))                              \
    {                                                  \
        for (int _i = 0; _i < sz(_r); _i++)            \
            cout << _r[_i] << " \n"[_i + 1 == sz(_r)]; \
    }
#define rv2(vv, r, c)                           \
    {                                           \
        (vv).assign((r), decltype((vv)[0])(c)); \
        for (auto &_r : (vv))                   \
            for (auto &_x : _r)                 \
                cin >> _x;                      \
    }
template <typename T>
vi mkv(int n, T v = 0) { return vi(n, v); }
template <typename T>
vector<T> mkvt(int n, T v = {}) { return vector<T>(n, v); }
template <typename T>
vector<vector<T>> mkv2(int r, int c, T v = {}) { return vector<vector<T>>(r, vector<T>(c, v)); }
inline vi iota_v(int n, int s = 0)
{
    vi a(n);
    iota(all(a), s);
    return a;
}
template <typename A, typename B>
void rp(pair<A, B> &p) { cin >> p.first >> p.second; }
template <typename A, typename B>
void pp(const pair<A, B> &p) { cout << p.first << " " << p.second << "\n"; }
template <typename T = int>
vector<T> rvec(int n)
{
    vector<T> v(n);
    for (auto &x : v)
        cin >> x;
    return v;
}
// Read r lines of a string grid
inline vs rvg(int r)
{
    vs g(r);
    for (auto &s : g)
        cin >> s;
    return g;
}
template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}
template <typename T, typename... Args>
void o(T first, Args... args)
{
    cout << first;
    ((cout << " " << args), ...);
    cout << "\n";
}
#define YES cout << "YES\n";
#define NO cout << "NO\n";
void solve()
{
    string s1, s2;
    r(s1, s2);
    int n = s1.length();
    int m = s2.length();
    vi a(n), b(m);
    rep(i, 0, n)
    {
        a[i] = s1[i] - '0';
    }
    rep(i, 0, m)
    {
        b[i] = s2[i] - '0';
    }
    vll pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];
    vll pre1(m + 1, 0);
    for (int i = 0; i < m; i++) pre1[i+1] = pre1[i] + b[i];
    vvi hikka(n, vi(10, -1));
    vvi hulle(m, vi(10, -1));
    rep(i, 0, n)
    {
        rep(j, 0, 10)
        {
            per(k, 0, i+1)
            {
                if((pre[i+1]-pre[k])%10 == j)
                {
                    hikka[i][j]=k;
                    break;
                }
            }
        }
    }
    // pv(pre);
    // pv(pre1);
    rep(i, 0, m)
    {
        rep(j, 0, 10)
        {
            per(k, 0, i+1)
            {
                if((pre1[i+1]-pre1[k])%10 == j)
                {
                    hulle[i][j]=k;
                    break;
                }
            }
        }
    }
    // pv2(hikka);
    // pv2(hulle);
    int dp[n+1][m+1];
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    rep(i, 0, n+1)
    {
        rep(j, 0, m+1)
        {
            rep(k, 0, 10)
            {
                if(i==0 && j==0) continue;
                else if(i==0)
                {
                    if(hulle[j-1][0]!=-1)
                    {
                        if(dp[0][hulle[j-1][0]]!=-1)
                        {
                            dp[i][j] = 0;
                        }
                    }
                    continue;
                }
                else if(j==0)
                {
                    if(hikka[i-1][0]!=-1)
                    {
                        if(dp[hikka[i-1][0]][0]!=-1)
                        {
                            dp[i][j] = 0;
                        }
                    }
                    continue;
                }
                if(hikka[i-1][k]!=-1 && hulle[j-1][k]!=-1)
                {
                    if(dp[hikka[i-1][k]][hulle[j-1][k]]!=-1)
                    {
                        dp[i][j] = max(dp[i][j], 1 + dp[hikka[i-1][k]][hulle[j-1][k]]);
                    }
                }
            }
        }
    }
    
    o(dp[n][m]);
}

signed main()
{
    fastIO();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}