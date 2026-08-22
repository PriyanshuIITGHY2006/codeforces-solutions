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
vi get_divisors(int n)
{
    vi d;
    for (int i = 1; (ll)i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }
    sort(all(d));
    return d;
}
void solve()
{
    int s, q;
    r(s, q);
    vi a = get_divisors(s);
    vi g(sz(a));
    vi sum(sz(a) + 1);
    sum[1] = s;
    rep(i, 1, sz(a))
    {
        sum[i + 1] = (a[i] - a[i - 1]) * (s / a[i]) + sum[i];
    }
    map<int, int> m;
    rep(i, 0, sz(a)) m[a[i]] = i;
    dbgv(a);
    while (q--)
    {
        int x, y;
        r(x, y);
        if (x > y)
            swap(x, y);
        if (y < a.back())
        {
            auto it1 = upper_bound(all(a), y);
            int index1 = m[s / (*it1)];
            int g = min(x, a[index1]) * y;
            auto it = upper_bound(all(a), x);
            int index = it - a.begin() - 1;
            int t = 0;
            if (index > index1)
                t = sum[index + 1] - sum[index1 + 1];
                int si = 0;
            if (x > a[index1])
                si = max(0ll, (min(a[index + 1], x) - a[index])) * (s / a[index + 1]);
            o(si + t + g);
        }
        else
        {
            if (x < a.back())
            {
                // auto it1 = upper_bound(all(a), y);
                // int index1 = m[s / (*it1)];
                int g = 0;
                // g = min(x, a[index1]) * y;
                auto it = upper_bound(all(a), x);
                int index = it - a.begin() - 1;
                int t = 0;
                t = sum[index + 1] - sum[0];
                int si = max(0ll, (min(a[index + 1], x) - a[index])) * (s / a[index + 1]);
                o(si + t + g);
            }
            else
            {
                o(sum.back());
            }
        }
    }
    // vi sum(sz(a) + 1);
    // sum[1] = s;
    // rep(i, 1, sz(a))
    // {
    //     sum[i + 1] = (a[i] - a[i - 1]) * (s / a[i]) + sum[i];
    // }
    // map<int, int> m;
    // rep(i, 0, sz(a)) m[a[i]] = i;
    // dbgv(a);
    // while (q--)
    // {
    //     int x, y;
    //     r(x, y);
    //     if (x > y)
    //         swap(x, y);
    //     auto it = upper_bound(all(a), y);
    //     int index = it - a.begin() - 1;
    //     auto it1 = upper_bound(all(a), x);
    //     int index1 = it1 - a.begin() - 1;
    //     dbg2(index, index1);
    //     index1 = m[s / a[index1]];
    //     dbg(index1);
    //     int t = 0;
    //     if (index >= index1 - 1)
    //         t = sum[index + 1] - sum[index1];
    //     int ti = 0;
    //     if (index1 != 0)
    //         ti = min(y, a[index1 - 1]) * x;
    //     int gi = 0;
    //     if (y > a[index])
    //         gi = (y - a[index]) * (s / a[index + 1]);
    //     dbg3(t, gi, ti);
    //     o(gi + ti + t);
    // }
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