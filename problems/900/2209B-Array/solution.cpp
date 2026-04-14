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
void solve() {
    int n;
    cin>>n;
    vll a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        int less=0;
        int even=0;
        for(int j=i; j<n; j++)
        {
            if(a[j]<a[i]) less++;
            else if(a[j]>a[i]) even++;
        }
        cout<<max(less, even)<<" ";
    }
    cout<<"\n";
}

int main() {
    fastIO();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}