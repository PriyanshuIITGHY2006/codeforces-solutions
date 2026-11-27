/*
 * ██████╗ ██████╗ ██╗██╗   ██╗ █████╗ ███╗   ██╗███████╗██╗  ██╗██╗   ██╗
 * ██╔══██╗██╔══██╗██║╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝██║  ██║██║   ██║
 * ██████╔╝██████╔╝██║ ╚████╔╝ ███████║██╔██╗ ██║███████╗███████║██║   ██║
 * ██╔═══╝ ██╔══██╗██║  ╚██╔╝  ██╔══██║██║╚██╗██║╚════██║██╔══██║██║   ██║
 * ██║     ██║  ██║██║   ██║   ██║  ██║██║ ╚████║███████║██║  ██║╚██████╔╝
 * ╚═╝     ╚═╝  ╚═╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝ ╚═════╝
 */
#include <algorithm>
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
struct MinSegTree {
    int n;
    vi tree;
    
    MinSegTree(int n) : n(n), tree(4*n, INF) {}
    
    void build(vi& a, int node, int l, int r) {
        if (l == r) { 
            tree[node] = a[l]; 
            return; 
        }
        int mid = (l + r) / 2;
        build(a, 2*node, l, mid);
        build(a, 2*node+1, mid+1, r);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
    void build(vi& a) { build(a, 1, 0, n-1); }
    
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { 
            tree[node] = val; 
            return; 
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else            update(2*node+1, mid+1, r, idx, val);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    
    int find_first(int node, int l, int r, int ql, int qr, int x) {
        if (qr < l || r < ql || tree[node] > x) return -1;
        if (l == r) return l;
        
        int mid = (l + r) / 2;
        int res = find_first(2*node, l, mid, ql, qr, x);
        
        if (res != -1) return res;
        return find_first(2*node+1, mid+1, r, ql, qr, x);
    }
    int find_first(int ql, int qr, int x) { 
        return find_first(1, 0, n-1, ql, qr, x); 
    }
};
void solve() {
    int n; r(n); vi a(n+1), b(n+1);
    rep(i, 1, n+1) r(a[i]);
    rep(i, 1, n+1) r(b[i]);
    vi c(n+1, INF);
    MinSegTree st(n+1);
    rep(i, 1, n+1){
        c[i] = i - a[i];
    }
    dbgv(c);
    st.build(c);
    map<int, vi> m;
    rep(i, 1, n+1){
        m[i+b[i]].pb(i);
    }
    for(auto &it : m){
        srt(it.se);
    }
    dbgm(m);
    vpii edges;
    set<int> s;
    rep(i, 1, n+1){
        if(c[i]==0){
            edges.pb(mp(i, 0));
            s.insert(i); st.update(i, INF); c[i]=INF;
        }
    }
    while(!s.empty()){
        set<int> sp;
        for(auto it : s){
            dbg(it);
            for(auto it1 : m[it]){
                dbg(it1);
                if(c[it1]!=INF) sp.insert(it1);
                edges.pb(mp(it1, it)); st.update(it1, INF); c[it1]=INF;
                while(true){
                    int idx = st.find_first(it1 + 1, n, it1); dbg(idx);
                    if (idx == -1) break;
                    sp.insert(idx);
                    edges.pb(mp(idx, it));
                    st.update(idx, INF); c[idx]=INF;
                }
            }
        }
        s=sp; dbg("ok"); dbgp(s);
    }
    vvi adj(n+1);
    for(auto it : edges){
        adj[it.fi].pb(it.se);
        // adj[it.se].pb(it.fi);
    }
    dbgv(edges);
    vll dist(n + 1, INF), route(n+1, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[n] = 0;
    pq.push({0, n});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1; route[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[0]==INF){
        o(-1); return;
    }
    else{
        dbgv(route);
        vi answer, ans; int cur = 0;
        while(cur!=n){
            answer.pb(cur);
            cur = route[cur];
        }
        rev(answer);
        o(dist[0]);
        int prev = n;
        for(auto it : answer){
            if(it!=0){
                    auto ita = upper_bound(all(m[it]), it);
                    ita--;
                    ans.pb(*ita);
                    prev = it;
            }
        }
        ans.pb(0); pv(ans);
    }
}

signed main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}