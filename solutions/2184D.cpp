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
const int MAXN = 31;
ll fact[MAXN], inv_fact[MAXN];
ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1; a %= mod;
    while (b > 0) {
        if (b & 1) res = ((res % mod) * (a%mod)) % mod;
        a = (a%mod) * (a%mod) % mod; b >>= 1;
    }
    return res;
}

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
void solve() {
    ll n, k;
    cin>>n>>k;
    ll first_one=__builtin_ctzll(n);
    dbg(first_one);
    ll max_k=first_one+1;
    dbg(max_k);
    first_one--;
    ll answer=0;
    while(first_one>=0 && first_one--)
    {
        dbg(first_one);
        ll possible_moves=k-1;
        dbg(possible_moves);
        if(possible_moves>=0)
        {
        ll max_1=possible_moves-(first_one+1);
        max_1=max(0ll, max_1);
        max_1 = min(max_1, first_one + 1);
        dbg(max_1);
        while(max_1--)
        {
            // ll zeroes=k-1-(max_1*2);
            dbg(max_1);
            ll t=(C(first_one+1, max_1+1));
            dbg(t);
            answer=answer+t;
        }
        if(first_one+2<=k) answer++;
        dbg(answer);
       }
    //    first_one--;
    }
    if(k>=1) answer++;
    if(max_k<=k) answer++;
    if(n!=1)
    cout<<binpow(2,__builtin_ctzll(n) )-answer<<"\n";
    else{
        if(k>=1) cout<<0<<"\n";
        else cout<<1<<"\n";
    }
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    precompute_factorials();
    dbgv(fact);
    while (t--) solve();
    return 0;
}