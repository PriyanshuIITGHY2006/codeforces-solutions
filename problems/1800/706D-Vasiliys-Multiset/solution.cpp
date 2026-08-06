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
string to_binary(ll x, int width = 0)
{
    string s;
    if (x == 0)
        s = "0";
    while (x > 0)
    {
        s += char('0' + (x & 1));
        x >>= 1;
    }
    reverse(all(s));
    while ((int)s.size() < width)
        s = "0" + s;
    return s;
}
struct trienode
{
    int value;
    trienode *left = nullptr;
    trienode *right = nullptr;
    trienode *parent = nullptr;
};
void add(trienode *root, int counter, string &s)
{
    if (counter < 30)
    {
        if (s[counter + 1] == '0')
        {
            if (root->left == nullptr) root->left = new trienode(); 
            add(root->left, counter + 1, s);
        }
        else
        {
            if (root->right == nullptr) root->right = new trienode();
            add(root->right, counter + 1, s);
        }
        int temp = 0;
        if(root->left!=nullptr) temp += root->left->value;
        if(root->right!=nullptr) temp += root->right->value;
        root->value = temp;
    }
    else
    {
        root->value++;
    }
}
void fuckoff(trienode *root, int counter, string &s)
{
    if (counter < 30)
    {
        if (s[counter + 1] == '0')
        {
            fuckoff(root->left, counter + 1, s);
        }
        else
        {
            fuckoff(root->right, counter + 1, s);
        }
        int temp = 0;
        if(root->left!=nullptr) temp += root->left->value;
        if(root->right!=nullptr) temp += root->right->value;
        root->value = temp;
    }
    else
    {
        root->value--;
    }
}
ll from_binary(const string& s) {
    ll x = 0;
    for (char c : s) x = (x << 1) | (c - '0');
    return x;
}
void solve()
{
    int q;
    r(q);
    trienode a;
    a.value = 1;
    trienode *curr = &a;
    rep(i, 0, 30)
    {
        trienode *root = new trienode();
        curr->left = root;
        root->value = 1;
        curr = root;
    }
    rep(i, 0, q)
    {
        char c;
        int x;
        r(c, x);
        string s = to_binary(x);
        rev(s);
        s.append(31 - sz(s), '0');
        if (c == '+')
        {
            rev(s);
            add(&a, 0, s);
        }
        else if (c == '-')
        {
            rev(s);
            fuckoff(&a, 0, s);
        }
        else
        {
            string siu = "0";
            trienode* curr = & a;
            rev(s);
            rep(i, 0, sz(s)-1)
            {
                if(s[i+1]=='0')
                {
                    if(curr->right != nullptr && curr->right->value > 0)
                    {
                        siu.pb('1');
                        curr = curr->right;
                    }
                    else
                    {
                        siu.pb('0');
                        curr = curr->left;
                    }
                }
                else
                {
                    if(curr->left != nullptr && curr->left->value > 0)
                    {
                        siu.pb('0');
                        curr = curr->left;
                    }
                    else
                    {
                        siu.pb('1');
                        curr = curr->right;
                    }
                }
            }
            int gian = from_binary(siu);
            o(gian ^ x);
        }
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