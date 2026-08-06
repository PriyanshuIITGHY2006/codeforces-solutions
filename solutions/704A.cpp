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
// #include "C:\msys64\home\priya\cp\templates\debug.hpp"
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

struct SegTree
{
    int n;
    vll tree, lazy;
    SegTree(int n) : n(n), tree(4 * n, 0), lazy(4 * n, 0) {}
    void push_down(int node)
    {
        if (lazy[node])
        {
            tree[2 * node] += lazy[node];
            lazy[2 * node] += lazy[node];
            tree[2 * node + 1] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void build(vll &a, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void build(vll &a) { build(a, 1, 0, n - 1); }
    void update(int node, int l, int r, int ql, int qr, ll val)
    {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr)
        {
            tree[node] += val;
            lazy[node] += val;
            return;
        }
        push_down(node);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int l, int r, ll val) { update(1, 0, n - 1, l, r, val); }
    ll query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        push_down(node);
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve()
{
    int n, q;
    r(n, q);
    
    // Create segment tree. It is initially all 0s. 
    // We update it to 1 dynamically when a new notification arrives.
    SegTree st(q + 1);
    
    vvi a(n + 1);
    vi b(n + 1, 0); // b[x] will now strictly track the index in a[x] that we have read up to
    
    int lastfull = 0;
    int counter = 0;
    
    while (q--)
    {
        int type;
        r(type);
        if (type == 1)
        {
            int x;
            r(x);
            a[x].pb(++counter);
            // Mark the new notification as unread (set to 1)
            st.update(counter, counter, 1);
        }
        else if (type == 2)
        {
            int x;
            r(x);
            // Iterate from the last processed index for app x
            for(int j = b[x]; j < sz(a[x]); j++) {
                int id = a[x][j];
                // Check if it's currently unread (might have been read by Type 3)
                if(st.query(id, id) == 1) {
                    st.update(id, id, -1);
                }
            }
            // Update the index to the end
            b[x] = sz(a[x]);
        }
        else
        {
            int t; r(t);
            // Process any unread notifications up to 't'
            while(lastfull < t) {
                lastfull++;
                if(st.query(lastfull, lastfull) == 1) {
                    st.update(lastfull, lastfull, -1);
                }
            }
        }
        
        // Output the total number of unread notifications after EVERY query
        // The total sum in the segment tree is stored at the root (st.tree[1])
        o(st.tree[1]); 
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