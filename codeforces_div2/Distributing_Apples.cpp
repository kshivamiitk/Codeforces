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
int modexp(int b, int e, int m){
    int res = 1;
    while(e > 0){
        if(e & 1) res = (res * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return res;
}
void precomputeFactorials(int N, vector<int>& fact, vector<int>& invfact){
    fact.resize(N+1);
    invfact.resize(N+1);
    fact[0] = 1;
    f(i, 1, N+1){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[N] = modexp(fact[N], mod - 2, mod);
    for(int i = N-1; i >= 0; i--){
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    int N = n + m;
    vector<int> fact, invfact;
    precomputeFactorials(N, fact, invfact);
    int ans = fact[n + m - 1];
    ans = (ans * invfact[n - 1]) % mod;
    ans = (ans * invfact[m]) % mod;
    cout << ans << endl;
}
signed main(){
    fast;
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
