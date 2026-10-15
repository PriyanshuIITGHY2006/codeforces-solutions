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
#include "templates/debug.hpp"
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
int fdiv(int a, int b){ return a/b - ((a%b) < 0); }
int cdiv(int a, int b){ return a/b + ((a%b) > 0); }
int rdiv(int a, int b){ return fdiv(2*a + b, 2*b); }
int fmod(int a, int b){ int r = a%b; return r + (b & -(r < 0)); }
int cntdiv(int l, int r, int d){ return fdiv(r, d) - fdiv(l - 1, d); }
int cntmod(int l, int r, int d, int k){ return fdiv(r - k, d) - fdiv(l - 1 - k, d); }
#define YES cout<< "YES\n";
#define NO cout<< "NO\n";
const int MAXN = 1e6+5;
vi spf(MAXN);
void spf_sieve() {
    iota(all(spf), 0);
    for (int i = 2; (ll)i*i < MAXN; i++)
        if (spf[i] == i) // i is prime
            for (int j = i*i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
}
map<int,int> factorize(int n) {
    map<int,int> f;
    while (n > 1) { f[spf[n]]++; n /= spf[n]; }
    return f;
}
void solve() {
    int n; r(n); vi a = rvec(n);
    map<int, int> m;
    rep(i, 0, n){
        map<int, int> yo = factorize(a[i]);
        int j = 1;
        for(auto it : yo){
            if(it.se%2==1) j*=it.fi;
        }
        m[j]++;
    }
    dbgm(m);
    set<int> odd;
    // int cur = 1;
    int answer = 0;
    int maxi = mx(a);
    rep(i, 0, n){
        map<int, int> yo = factorize(a[i]);
        dbgm(yo);
        for(auto it : yo){
            if((it.se%2)==1) {if(odd.find(it.fi)==odd.end()) {odd.insert(it.fi); } else {odd.erase(it.fi);}}
        }
        int cur = 1; int possible = true;
        for(auto it : odd){
            if(cur*it > maxi) {possible = false; break;}
            else cur*=it;
        }
        if(possible) if(m.find(cur)!=m.end())answer += m[cur];
    }
    o(answer);
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    spf_sieve();
    while (t--) solve();
    return 0;
}