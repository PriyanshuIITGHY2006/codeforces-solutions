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
struct SegTree {
    int n;
    vi tree;
    SegTree(const vi& arr) {
        n = sz(arr);
        tree.assign(4 * n, INF);
        if(n > 0) build(arr, 0, 0, n - 1);
    }

    void build(const vi& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        int lc = 2 * node + 1;
        int rc = 2 * node + 2;
        build(arr, lc, start, mid);
        build(arr, rc, mid + 1, end);
        tree[node] = min(tree[lc], tree[rc]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return INF; 
        if (l <= start && end <= r) return tree[node];
        int mid = start + (end - start) / 2;
        return min(query(2 * node + 1, start, mid, l, r),
                   query(2 * node + 2, mid + 1, end, l, r));
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        int lc = 2 * node + 1;
        int rc = 2 * node + 2;
        
        if (start <= idx && idx <= mid) {
            update(lc, start, mid, idx, val);
        } else {
            update(rc, mid + 1, end, idx, val);
        }
        tree[node] = min(tree[lc], tree[rc]);
    }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
};
void solve()
{
    int n, m, q;
    r(n, m, q);
    vi a = rvec(n);
    vi b = rvec(m);
    vpii adj(n + 1);
    rep(i, 0, n)
    {
        if (i != 0 && i != n - 1)
        {
            adj[a[i]].fi = a[i - 1];
            adj[a[i]].se = a[i + 1];
        }
        else if (i == 0)
        {
            adj[a[i]].fi = a[n - 1];
            adj[a[i]].se = a[i + 1];
        }
        else
        {
            adj[a[i]].fi = a[i - 1];
            adj[a[i]].se = a[0];
        }
    }
    map<int, vi> freq;
    rep(i, 0, m)
    {
        freq[b[i]].pb(i);
    }
    const int LOG = 20; 
    vvi up(m + 1, vi(LOG, m)); 

    per(i, 0, m)
    {
        auto it = lower_bound(all(freq[adj[b[i]].se]), i);
        if (it != freq[adj[b[i]].se].end())
        {
            up[i][0] = *it;
        }
        rep(j, 1, LOG)
        {
            if (up[i][j - 1] < m)
            {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    vi min_end(m, m);
    
    rep(i, 0, m)
    {
        int curr = i;
        int steps = n - 1;
        rep(j, 0, LOG)
        {
            if ((steps >> j) & 1)
            {
                curr = up[curr][j];
                if (curr == m) break;
            }
        }
        min_end[i] = curr;
    }
    // pv(min_end);
    SegTree st(min_end);
    while (q--)
    {
        int li, ri;
        r(li, ri);
        li--; ri--; 
        int ans = st.query(li, ri);
        
        if(ans<=ri) cout<<1;
        else cout<<0;
    }

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