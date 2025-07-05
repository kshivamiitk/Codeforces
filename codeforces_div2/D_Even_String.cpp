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
#define mod 998244353
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<int, vector<int>, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define pi_const 3.1415926535897932384626433832795
#define eps 1e-9
vi fact, invfact;

int modexp(int a, int b) {
    int res = 1;
    a %=mod;
    while(b>0) {
    if(b&1)
        res=(res *a)% mod;
        a =(a * a)% mod;
        b>>=1;
    }
    return res;
}

void precomp(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[n] =modexp(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }
}

void solve(){
    vi arr(26, 0);
    rep(i,26) cin >> arr[i];
    int tot = accumulate(all(arr), 0LL);
    int odd = (tot + 1) / 2;
    int even = tot / 2;
    vi dp(odd + 1, 0), newdp(odd + 1, 0);
    dp[0] = 1;
    rep(i,26){
        fill(all(newdp), 0);
        rep(j, odd + 1){
            if(dp[j] == 0) continue;
            if(arr[i]== 0){
                newdp[j]=(newdp[j] + dp[j]) % mod;
            }
            else{
            if(j+arr[i] <=odd){
                    newdp[j +arr[i]] = (newdp[j+arr[i]] +dp[j]) % mod;
                }
            if(arr[i] <= even){
                    newdp[j]= (newdp[j]+dp[j]) % mod;
                }
            }
        }dp.swap(newdp);
    }
    
    int valid = dp[odd] % mod;
    int num = (fact[odd] * fact[even]) % mod;
    rep(i,26){
        num = (num * invfact[arr[i]]) % mod;
    }
    
    int answer = (valid * num) % mod;
    cout << answer << endl;
}

signed main(){
    fast;
    // Precompute factorials up to 500000 (the maximum total letter count per test case).
    int max_n = 500000;
    precomp(max_n);
    
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
