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
using Node = pair<int, pair<int, int>>;

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        if (a.second.second != b.second.second) {
            return a.second.second < b.second.second; 
        }
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second.first < b.second.first;
    }
};

void solve() {
    int n, m; string s; r(n,m,s);
    vll rows(n,0), columns(m,0); 
    vvll a(n, vll(m)); 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            r(a[i][j]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        ll sum=0;
        for(int j=0; j<m; j++)
        {
            sum += a[i][j];
        }
        rows[i]=sum;
    }
    for(int i=0; i<m; i++)
    {
        ll sum=0;
        for(int j=0; j<n; j++)
        {
            sum += a[j][i];
        }
        columns[i]=sum;
    }
    
    vi rowd(n,0), columnd(m,0);
    rowd[0]++; columnd[0]++;
    int l=0, j=0;
    
    vector<set<int>> rowdi(n), columdi(m); 
    rowdi[0].insert(0);
    columdi[0].insert(0);
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='D') {
            l++;
        } else {
            j++;
        }
        rowd[l]++;
        columnd[j]++;
        columdi[j].insert(l); 
        rowdi[l].insert(j);
    }
    
    set<Node, CompareNode> s_pq;

    for(int i=0; i<n; i++) {
        s_pq.insert({0, {i, rowd[i]}});
    }
    for(int i=0; i<m; i++) {
        s_pq.insert({1, {i, columnd[i]}});
    }
    
    while(!s_pq.empty())
    {
        Node temp = *s_pq.begin();
        s_pq.erase(s_pq.begin());
        
        int type = temp.first;
        int idx = temp.second.first;
        int degree = temp.second.second;

        if(degree == 0) continue; 
        
        if(type == 0) 
        {
            if (rowdi[idx].empty()) continue;
            
            int col_idx = *rowdi[idx].begin(); 
            
            ll missing_val = -rows[idx];
            a[idx][col_idx] = missing_val; 
            
            rows[idx] = 0; 
            columns[col_idx] += missing_val; 
            
            rowdi[idx].erase(col_idx); 
            
            s_pq.erase({1, {col_idx, columnd[col_idx]}});
            columdi[col_idx].erase(idx); 
            columnd[col_idx]--;
            s_pq.insert({1, {col_idx, columnd[col_idx]}});
        }
        else if (type == 1)
        {
            if (columdi[idx].empty()) continue;
            
            int row_idx = *columdi[idx].begin(); 
            
            ll missing_val = -columns[idx];
            a[row_idx][idx] = missing_val; 
            
            columns[idx] = 0; 
            rows[row_idx] += missing_val; 
            
            columdi[idx].erase(row_idx);
            
            s_pq.erase({0, {row_idx, rowd[row_idx]}});
            rowdi[row_idx].erase(idx);
            rowd[row_idx]--; 
            s_pq.insert({0, {row_idx, rowd[row_idx]}});
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastIO();
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}