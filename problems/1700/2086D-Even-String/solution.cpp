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
#include <numeric>
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
const ll  MOD  = 998244353;
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
ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return res;
}
const int MAXN = 5e5+5;
ll fact[MAXN], inv_fact[MAXN];

void precompute_factorials(int n = MAXN - 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[n] = binpow(fact[n], MOD - 2);
    for (int i = n-1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] % MOD * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}

ll P(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] % MOD * inv_fact[n-r] % MOD;
}
// Modular inverse using Fermat's little theorem (mod must be prime)
ll modinv(ll a, ll mod = MOD) { return binpow(a, mod - 2, mod); }
void solve() {
    vi a = rvec(26);
    vi b; rep(i, 0, 26) if(a[i]!=0) b.pb(a[i]); int n = sz(b);
    int answer = 0;
    int tot = accumulate(all(a), 0ll);
    if(tot%2==0){
        vi dp((tot/2)+1, -1);
        dp[0] = 1;
        rep(i, 0, n){
            per(j, 0, (tot/2)+1){
                // if(dp[j]!=-1)
                //     {if((j + b[i]) < ((tot/2) + 1)){
                //         if(dp[j+b[i]]!=-1) dp[j + b[i]] += dp[j] ; else dp[j+b[i]] = dp[j];
                //     }}
                if((j-b[i]>=0) && (dp[j-b[i]]!=-1)) dp[j] = max(dp[j], 0ll) + dp[j-b[i]];
            }
            // pv(dp);
        }
        // o(dp[tot/2]);
        int answer = (fact[tot/2] * fact[tot/2])%MOD;
        // o(answer);
        rep(i, 0, n){
            answer = (answer * modinv(fact[b[i]]))%MOD;
        }
        // o(answer);
        o(answer *( max(0ll, dp[tot/2]))%MOD);
    }
    else{
        vi dp((tot/2)+1, -1);
        dp[0] = 1;
        rep(i, 0, n){
            per(j, 0, (tot/2)+1){
                // if(dp[j]!=-1)
                //     {if((j + b[i]) < ((tot/2) + 1)){
                //         if(dp[j+b[i]]!=-1) dp[j + b[i]] += dp[j] ; else dp[j+b[i]] = dp[j];
                //     }}
                if((j-b[i]>=0) && (dp[j-b[i]]!=-1)) dp[j] = max(dp[j], 0ll) + dp[j-b[i]];
            }
            // pv(dp);
        }
        // o(dp[tot/2]);
        int answer = (fact[tot/2] * fact[(tot+1)/2])%MOD;
        // o(answer);
        rep(i, 0, n){
            answer = (answer * modinv(fact[b[i]]))%MOD;
        }
        // o(answer);
        o(answer *( max(0ll, dp[tot/2]))%MOD);
    }
}

signed main() {
    fastIO();
    int t = 1;
    cin >> t;
    precompute_factorials();
    while (t--) solve();
    return 0;
}