#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<iomanip>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define vc vector<char>
#define vb vector<bool>
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

void solve() {
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi x(n, vi(2, 0)), y(n, vi(2, 0));
    for (int i = 1; i <= n - 2; i++) {
        ll ai = a[i];
        ll L, U;
        if (ai <= 2 * s) {
            L = max(0LL, ai - s);
            U = min((ll)s, ai); 
        } else {
            L = s;
            U = ai - s;
        }
        x[i][0] = L;
        x[i][1] = U;
        y[i][0] = ai - L;
        y[i][1] = ai - U;
    }
    vvi dp(n, vi(2, 0));
    const ll INF = LLONG_MAX;
    rep(i, n) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = a[0] * x[1][0];
    dp[1][1] = a[0] * x[1][1];
    for (int i = 2; i <= n - 2; i++) {
        rep(b, 2) {
            ll best = INF;
            rep(p, 2) {
                best = min(best, dp[i - 1][p] + y[i - 1][p] * x[i][b]);
            }
            dp[i][b] = best;
        }
    }
    ll answer = INF;
    rep(b, 2) {
        answer = min(answer, dp[n - 2][b] + y[n - 2][b] * a[n - 1]);
    }

    cout << answer << endl;
}

signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
