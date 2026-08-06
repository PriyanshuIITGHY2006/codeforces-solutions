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
// #include "C:\msys64\home\priya\cp\templates\debug.hpp"
#else
#define dbg(x)
#define dbg2(x,y)
#define dbg3(x,y,z)
#define dbgv(v)
#define dbgvv(vv)
#define dbgm(m)
#define dbgp(p)
#define dbgg(g)
#define dbgg_un(g)
#define dbgf(v)
#define dbg_range(b,e)
#define dbg_if(c,x)
#define dbg_diff(a,b)
#define dbg_assert(c,...)
#define dbg_time()
#define here()
#define SCOPE(name)
#define TIMER(name)
#define TICK(name)
#define TICKL(name,label)
#define WATCH(type,name,init) type name = init
#define DBG_SEP(label)
#define DBG_BANNER(s)
#endif
#define int long long
using ll   = long long;
using ull  = unsigned long long;
using ld   = long double;
using pii  = pair<int,int>;
using pll  = pair<ll,ll>;
using vi   = vector<int>;
using vll  = vector<ll>;
using vs   = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi  = vector<vi>;
using vvll = vector<vll>;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const ll  MOD  = 1e9 + 7;
const ll  INF  = 1e18;
const int IINF = 1e9;
const ld  EPS  = 1e-9;
const ld  PI   = acos((ld)-1);
#define fastIO()   ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x)     (x).begin(),(x).end()
#define rall(x)    (x).rbegin(),(x).rend()
#define sz(x)      ((int)(x).size())
#define pb         push_back
#define eb         emplace_back
#define fi         first
#define se         second
#define mp         make_pair
#define rep(i,a,b) for (int i=(a); i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
#define each(a,x)  for (auto& a : (x))
#define srt(v)     sort(all(v))
#define rsrt(v)    sort(rall(v))
#define uni(v)     srt(v); (v).erase(unique(all(v)),(v).end())
#define sm(v)      accumulate(all(v), 0LL)
#define mn(v)      *min_element(all(v))
#define mx(v)      *max_element(all(v))
#define rev(v)     reverse(all(v))
#define popcnt(x)  __builtin_popcountll(x)
#define lsb(x)     ((x) & -(x))
#define nl cout << "\n"
#define rv(v)        for (auto& _x : (v)) cin >> _x;
#define pv(v)        { for (int _i=0;_i<sz(v);_i++) cout<<(v)[_i]<<" \n"[_i+1==sz(v)]; }
#define pvn(v)       for (auto& _x : (v)) cout << _x << "\n"
#define pv2(vv)      for (auto& _r:(vv)){ for(int _i=0;_i<sz(_r);_i++) cout<<_r[_i]<<" \n"[_i+1==sz(_r)]; }
#define rv2(vv,r,c)  { (vv).assign((r),decltype((vv)[0])(c)); for(auto& _r:(vv)) for(auto& _x:_r) cin>>_x; }
template<typename T> vi  mkv (int n, T v=0)         { return vi(n, v); }
template<typename T> vector<T> mkvt(int n, T v={})  { return vector<T>(n, v); }
template<typename T> vector<vector<T>> mkv2(int r, int c, T v={}) { return vector<vector<T>>(r, vector<T>(c, v)); }
inline vi iota_v(int n, int s=0) { vi a(n); iota(all(a), s); return a; }
template<typename A,typename B> void rp(pair<A,B>& p)        { cin >> p.first >> p.second; }
template<typename A,typename B> void pp(const pair<A,B>& p)  { cout << p.first << " " << p.second << "\n"; }
template<typename T=int> vector<T> rvec(int n){ vector<T> v(n); for(auto& x:v) cin>>x; return v; }
// Read r lines of a string grid
inline vs rvg(int r){ vs g(r); for(auto& s:g) cin>>s; return g; }
template<typename... T>
void r(T&... args) {
    ((cin >> args), ...);
}
template<typename T, typename... Args>
void o(T first, Args... args) {
    cout << first;
    ((cout << " " << args), ...); 
    cout << "\n";
}
#define YES cout<< "YES\n";
#define NO cout<< "NO\n";
struct segtree
{
    int n;
    vi val;
    vi tree;
    vector<vector<bool>> tree1;
    segtree(const vi &a)
    {
        n = sz(a);
        val = a;
        tree.assign(4 * n, 0);
        tree1.assign(4 * n, vector<bool>(26, false));
        if (n > 0)
        {
            build(1, 0, n - 1);
        }
    }
    void build(int number, int li, int ri)
    {
        if (li == ri)
        {
            tree[number] = 1;
            tree1[number][val[li]]=true;
            return;
        }
        int mid = (li + ri) / 2;
        build(2 * number, li, mid);
        build(2 * number + 1, mid + 1, ri);
        rep(i, 0, 26)
        {
            if(tree1[2*number][i] || tree1[2*number + 1][i])
            {
                tree1[number][i] = true;
            }
            else tree1[number][i] = false;
        }
        tree[number] = count(all(tree1[number]), true);
        return;
    }
    void update(int li, int ri, int index, int i, int naya)
    {
        if (li == ri)
        {
            rep(j, 0, 26)
            {
                tree1[index][j] = false;
            }
            tree1[index][naya] = true;
            return;
        }
        int mid = (li + ri) / 2;
        if (mid >= i)
        {
            update(li, mid, 2 * index, i, naya);
        }
        else
        {
            update(mid+1, ri, 2 * index + 1, i, naya);
        }
        rep(i, 0, 26)
        {
            if(tree1[2*index][i] || tree1[2*index + 1][i])
            {
                tree1[index][i] = true;
            }
            else tree1[index][i] = false;
        }
        tree[index] = count(all(tree1[index]), true);
    }
    void query(int li, int ri, int index, int left, int right, vector<bool> & arr)
    {
        if (li >= left && ri <= right)
            {
                rep(i, 0, 26)
                {
                    if(tree1[index][i]) arr[i] = true;
                }
            }
        else if (li > right || ri < left)
            return;
        else
        {
            int mid = (li + ri) / 2;
            query(li, mid, 2 * index, left, right, arr);
            query(mid + 1, ri, 2 * index + 1, left, right, arr);
            return;
        }
    }
    void update(int i, char c)
    {
        update(0, n - 1, 1, i, c - 'a');
    }
    int query(int li, int ri)
    {
        vector<bool> arr(26, false);
        query(0, n-1, 1, li, ri, arr);
        return count(all(arr), true);
    }
};
void solve() {
    string s; r(s);
    int n = sz(s); vi a (n);
    rep(i, 0, n)
    {
        a[i] = s[i]-'a';
    }
    segtree st(a);
    int q; r(q);
    rep(i, 0, q)
    {
        int type; r(type);
        if(type==1){
            int index; char c;
            r(index, c);
            st.update(index-1, c);
        }
        else
        {
            int li, ri; r(li, ri);
            o(st.query(li-1, ri-1));
        }
    }
}

signed main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}