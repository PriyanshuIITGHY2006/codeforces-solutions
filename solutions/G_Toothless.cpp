#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;
const ld PI = acos(-1);

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); ++i)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) for (int i = (a)-1; i >= 0; --i)
#define each(a, x) for (auto &a : x)

#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define uni(v) srt(v); (v).erase(unique(all(v)), (v).end()) 
#define sm(v) accumulate(all(v), 0LL) 
#define mn(v) *min_element(all(v))
#define mx(v) *max_element(all(v))
#define rev(v) reverse(all(v))

#define popcnt(x) __builtin_popcountll(x)
#define lsb(x) ((x) & -(x))

ll binpow(ll a, ll b) {
    ll res = 1; a %= MOD;
    while (b > 0) { if (b & 1) res = (res * a) % MOD; a = (a * a) % MOD; b >>= 1; }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

vector<bool> is_prime_sieve;
void sieve(int n) {
    is_prime_sieve.assign(n + 1, true);
    is_prime_sieve[0] = is_prime_sieve[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i <= n; i += p) is_prime_sieve[i] = false;
        }
    }
}

map<ll, int> prime_factorization(ll n) {
    map<ll, int> factors;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) { factors[d]++; n /= d; }
    }
    if (n > 1) factors[n]++;
    return factors;
}

ll kadane(const vll& arr) {
    ll max_so_far = -INF, current_max = 0;
    for (ll x : arr) {
        current_max += x;
        if (current_max > max_so_far) max_so_far = current_max;
        if (current_max < 0) current_max = 0;
    }
    return max_so_far;
}

struct DSU {
    vi parent;
    DSU(int n) { parent.resize(n + 1); iota(all(parent), 0); }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) { parent[root_i] = root_j; return true; }
        return false;
    }
};

struct FenwickTree {
    vll bit; int size;
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}
    void update(int idx, ll delta) { for (; idx <= size; idx += idx & -idx) bit[idx] += delta; }
    ll query(int idx) { ll sum = 0; for (; idx > 0; idx -= idx & -idx) sum += bit[idx]; return sum; }
    ll queryRange(int l, int r) { return query(r) - query(l - 1); }
};

void solve() {
    int n; cin >> n;
    vll a(n);
    F0R(i, n) cin >> a[i];

    cout << n << "\n";
}

int main() {
    fastIO();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}