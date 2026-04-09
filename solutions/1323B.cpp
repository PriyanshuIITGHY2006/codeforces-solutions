#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DC  "\033[36m"
#define DY  "\033[33m"
#define DR  "\033[31m"
#define DG  "\033[32m"
#define DX  "\033[0m"

#define dbg(x)        cerr << DC "[" #x "]" DX " = " << DY << (x) << DX << "\n"
#define dbg2(x,y)     cerr << DC "[" #x ", " #y "]" DX " = " << DY << (x) << ", " << (y) << DX << "\n"
#define dbg3(x,y,z)   cerr << DC "[" #x "," #y "," #z "]" DX " = " << DY << (x) << "," << (y) << "," << (z) << DX << "\n"
#define dbgv(v)       { cerr << DC "[" #v "]" DX " = [ "; for (auto& _e : (v)) cerr << DY << _e << DX << " "; cerr << "]\n"; }
#define dbgvv(vv)     { cerr << DC "[" #vv "]" DX ":\n"; for (int _i = 0; _i < (int)(vv).size(); _i++) { cerr << "  row " << DG << _i << DX << ": [ "; for (auto& _e : (vv)[_i]) cerr << DY << _e << DX << " "; cerr << "]\n"; } }
#define dbgm(m)       { cerr << DC "[" #m "]" DX ":\n"; for (auto& [_k,_v] : (m)) cerr << "  " << DG << _k << DX << " -> " << DY << _v << DX << "\n"; }
#define dbgp(p)       cerr << DC "[" #p "]" DX " = (" << DY << (p).first << ", " << (p).second << DX << ")\n"
#define here()        cerr << DR ">> LINE " << __LINE__ << " [" << __FUNCTION__ << "]" << DX << "\n"
#define dbg_assert(c) { if (!(c)) { cerr << DR "[ASSERT FAILED] " #c " line " << __LINE__ << DX << "\n"; exit(1); } }
#define dbg_time()    { static auto _t = chrono::steady_clock::now(); auto _n = chrono::steady_clock::now(); cerr << DR "[TIME] " << chrono::duration_cast<chrono::milliseconds>(_n - _t).count() << "ms" << DX << "\n"; _t = _n; }
#else

#define dbg(x)
#define dbg2(x,y)
#define dbg3(x,y,z)
#define dbgv(v)
#define dbgvv(vv)
#define dbgm(m)
#define dbgp(p)
#define here()
#define dbg_assert(c)
#define dbg_time()
#endif
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
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define F0R(i,n)   for (int i=0; i<(n); ++i)
#define ROF(i,a,b) for (int i=(b)-1; i>=(a); --i)
#define R0F(i,n)   for (int i=(n)-1; i>=0; --i)
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
template<typename T=ll> vector<T> rvec(int n){ vector<T> v(n); for(auto& x:v) cin>>x; return v; }
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
    int n, m; ll k; r(n, m, k); 
    vll a = rvec(n);
    vll b = rvec(m);
    map<ll, int> acont, bcont;
    int temp=0;
    for(int i=0; i<n; i++) {
        if(a[i]==1) temp++;
        else {
            if (temp > 0) acont[temp]++;
            temp=0;
        }
    }
    if (temp > 0) acont[temp]++;
    temp=0;
    for(int i=0; i<m; i++) {
        if(b[i]==1) temp++;
        else {
            if (temp > 0) bcont[temp]++;
            temp=0;
        }
    }
    if (temp > 0) bcont[temp]++;

    ll total_subrectangles = 0;
    for (ll x = 1; x <= n; x++) {
        if (k % x == 0) {
            ll y = k / x;
            if (y <= m) {
                ll waysA = 0;
                ll waysB = 0;
                for (auto const& [len, count] : acont) {
                    if (len >= x) waysA += (len - x + 1) * count;
                }
                for (auto const& [len, count] : bcont) {
                    if (len >= y) waysB += (len - y + 1) * count;
                }
                total_subrectangles += waysA * waysB;
            }
        }
    }
    
    o(total_subrectangles);
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}