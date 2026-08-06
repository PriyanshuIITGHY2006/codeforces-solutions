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
void solve() {
    int n, m; r(n, m);
    int a[n][m];
    rep(i, 0, n){
        rep(j, 0, m)
        {
            r(a[i][j]);
        }
    }
    vvi firsttothis(n, vi(m, -INF)), thistolast(n, vi (m, -INF));
    
    auto valid = [&](int i , int j)->bool{
        if(i<n && i>=0 && j<m && j>=0) return true;
        else return false;
    };
    
    firsttothis[0][0] = a[0][0];
    rep(i, 0, n)
    {
        rep(j, 0, m){ 
            if(i==0 && j==0) continue;
            if(valid(i-1, j))
            {
                firsttothis[i][j] = max(firsttothis[i-1][j]+a[i][j], firsttothis[i][j]);
            }
            if(valid(i, j-1))
            {
                firsttothis[i][j] = max(firsttothis[i][j-1]+a[i][j], firsttothis[i][j]);
            }
        }
    }
    
    thistolast[n-1][m-1] = a[n-1][m-1];
    per(i, 0, n)
    {
        per(j, 0, m){
            if(i==n-1 && j==m-1) continue;
            if(valid(i+1, j))
            {
                thistolast[i][j] = max(thistolast[i+1][j] + a[i][j], thistolast[i][j]);
            }
            if(valid(i, j+1))
            {
                thistolast[i][j] = max(thistolast[i][j+1] + a[i][j], thistolast[i][j]);
            }
        }
    }
    
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            firsttothis[i][j] +=(thistolast[i][j]-a[i][j]);
        }
    }
    
    int answer = INF;
    vvi dp(n+1, vi(m+1, -INF));
    vvi dp1(n+1, vi(m+1, -INF));
    
    rep(i, 1, n+1)
    {
        rep(j, 1, m+1)
        {
            dp[i][j]= max(firsttothis[i-1][j-1], dp[i][j-1]);
        }
    }
    
    per(i, 0, n)
    {
        per(j, 0, m) 
        {
            dp1[i][j] = max(firsttothis[i][j], dp1[i][j+1]); 
        }
    }
    
    answer = firsttothis[0][0] - 2*a[0][0];
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            int temp;
            if(i==0 && j==0) continue;
            temp = firsttothis[i][j]-2*a[i][j];
            
            if(valid(i+1, j-1))
            {
                    temp = max(temp, dp[i+2][j]);
            }
            if(valid(i-1, j+1))
            {
                temp = max(temp, dp1[i-1][j+1]);
            }
            answer = min(answer, temp);
        }
    }
    o(answer);
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}