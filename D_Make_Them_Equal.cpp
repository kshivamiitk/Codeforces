#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<int, vector<int>, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

// (Your existing modexp / factorial code—left unused but retained per boilerplate)
int modexp(int a, int b) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> fact, invfact;
void precomp(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[n] = modexp(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}

// --- BEGIN CORRECTION: precompute minOps via BFS ---
static vector<int> minOps;
void buildMinOps(int MAXB = 1000) {
    minOps.assign(MAXB+1, LLONG_MAX);
    queue<int> q;
    minOps[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int d = minOps[u];
        for (int x = 1; x <= u; ++x) {
            int v = u + u / x;
            if (v > MAXB) continue;
            if (minOps[v] > d + 1) {
                minOps[v] = d + 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    int n; 
    ll k;
    cin >> n >> k;
    vi brr(n);
    rep(i, n) cin >> brr[i];
    vi crr(n);
    rep(i, n) cin >> crr[i];
    vector<int> w(n);
    ll sumW = 0;
    rep(i, n) {
        w[i] = minOps[brr[i]];
        sumW += w[i];
    }
    int K = (int)min<ll>(k, sumW);
    vector<ll> dp(K+1, 0);
    rep(i, n) {
        int wi = w[i];
        ll ci = crr[i];
        if (wi > K) continue;
        for (int j = K; j >= wi; --j) {
            dp[j] = max(dp[j], dp[j - wi] + ci);
        }
    }
    ll ans = 0;
    rep(j, K+1) ans = max(ans, dp[j]);
    cout << ans << endl;
}

signed main(){
    fast;
    buildMinOps();          
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
