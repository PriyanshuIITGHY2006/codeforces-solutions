/*
 * ██████╗ ██████╗ ██╗██╗   ██╗ █████╗ ███╗   ██╗███████╗██╗  ██╗██╗   ██╗
 * ██╔══██╗██╔══██╗██║╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝██║  ██║██║   ██║
 * ██████╔╝██████╔╝██║ ╚████╔╝ ███████║██╔██╗ ██║███████╗███████║██║   ██║
 * ██╔═══╝ ██╔══██╗██║  ╚██╔╝  ██╔══██║██║╚██╗██║╚════██║██╔══██║██║   ██║
 * ██║     ██║  ██║██║   ██║   ██║  ██║██║ ╚████║███████║██║  ██║╚██████╔╝
 * ╚═╝     ╚═╝  ╚═╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝
 */
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
    int n;
    r(n);
    vi val = rvec(n);
    vvi adj(n + 1);
    rep(i, 0, n - 1)
    {
        int u, v;
        r(u, v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vpii sub(n + 1, {1, 0});

    function<void(int, int)> dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            sub[u].fi += sub[v].se;
            sub[u].se += sub[v].fi;
        }
    };
    dfs(1, 0);
    vll sub1(n + 1, 1);

    function<void(int, int)> dfs2 = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs2(v, u);
            sub1[u] += sub1[v];
        }
    };
    dfs2(1, 0);
    dbgv(sub1);
    dbgv(sub);
    int answer = 0;
    function<void(int, int)> dfs1 = [&](int u, int p)
    {
        dbg(u);
        dbgv(sub);
        
        int cur_val = (val[u - 1] % MOD + MOD) % MOD;
        int neg_val = (-val[u - 1] % MOD + MOD) % MOD;
        
        answer = (answer + sub1[u] % MOD * cur_val % MOD) % MOD;
        for (int v : adj[u])
        {
            int ways = ((sub1[u] - sub1[v]) % MOD + MOD) % MOD;
            answer = (answer + ways * sub[v].se % MOD * cur_val % MOD) % MOD;
            answer = (answer + ways * sub[v].fi % MOD * neg_val % MOD) % MOD;
        }
        
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            int oldsub1u = sub1[u], oldsub1v = sub1[v];
            pii oldsubu = sub[u], oldsubv = sub[v];
            sub[u] = {oldsubu.fi - oldsubv.se, oldsubu.se - oldsubv.fi};
            sub[v] = {oldsubv.fi + sub[u].se, oldsubv.se + sub[u].fi};
            sub1[u] = oldsub1u - sub1[v];
            sub1[v] = oldsub1u;
            dfs1(v, u);
            sub[u] = oldsubu;
            sub[v] = oldsubv;
            sub1[u] = oldsub1u;
            sub1[v] = oldsub1v;
        }
    };
    dfs1(1, 0);
    
    answer = (answer % MOD + MOD) % MOD;
    o(answer);
}

signed main()
{
    fastIO();
    int t = 1;
    while (t--)
        solve();
    return 0;
}