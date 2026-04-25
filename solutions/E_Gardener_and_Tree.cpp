#include <bits/stdc++.h>
using namespace std;

// ─── DEBUG ───────────────────────────────────────────
#ifdef DEBUG
  #define dbg(x)   cerr << "[" << #x << "] = " << (x) << "\n"
  #define dbgv(v)  cerr << "[" << #v << "] = "; for(auto& _e : v) cerr << _e << " "; cerr << "\n"
  #define dbgm(m)  cerr << "[" << #m << "]:\n"; for(auto& [k,v] : m) cerr << "  " << k << " -> " << v << "\n"
  #define here()   cerr << ">> reached line " << __LINE__ << "\n"
#else
  #define dbg(x)
  #define dbgv(v)
  #define dbgm(m)
  #define here()
#endif

// ─── ALIASES ─────────────────────────────────────────
using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vl  = vector<ll>;

// ─── CONSTANTS ───────────────────────────────────────
const int  INF  = 1e9;
const ll   LINF = 1e18;
const int  MOD  = 1e9 + 7;

// ─── MACROS ──────────────────────────────────────────
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define pb          push_back
#define ff          first
#define ss          second
#define sz(x)       (int)(x).size()
#define rep(i,a,b)  for(int i = (a); i < (b); i++)

// ─── SOLUTION ────────────────────────────────────────
void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
