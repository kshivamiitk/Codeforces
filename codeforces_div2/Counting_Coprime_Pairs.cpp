/**
 * this question is to calculate the number of coprime pairs
 * this can be done using the concept of factors, suppose 
*/
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
bool isprime(int n) {
    if(n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
vi precompute(int n){
    // this is for the purpose of calculation of mu so that it can find the mu in just order 1
    // this is going to go for any sieve method, like you have to sieve the whole graph out
    vi primes;
    vi mu(n + 1, 1);
    
    vector<bool> comp(n + 1 , false);
    mu[1] = 1;
    for(int i = 2 ; i <= n ; i++){
        if(!comp[i]){
            primes.pb(i);
            mu[i] = -1;
        }
        for(auto p : primes){
            if(i * p > n ) break;
            comp[i * p] = true;
            if(i % p == 0){
                mu[i * p] = 0 ;
                break;
            }else{
                mu[i * p] = -mu[i];
            }
        }
    }
    return mu;
}
// int mu(int n) {
//     if(n == 1) return 1;
//     int c = 0;
//     int count = 0;
//     while(n % 2 == 0) {
//         n /= 2;
//         count++;
//     }
//     if(count > 1) return 0;
//     if(count == 1) c++;
//     for(int i = 3; i * i <= n; i++) {
//         count = 0;
//         while(n % i == 0) {
//             count++;
//             n /= i;
//         }
//         if(count > 1) return 0;
//         if(count == 1) c++;
//     }
//     if(n > 1) c++;
//     return (c % 2) ? -1 : 1;
// }

int nC2(int n) {
    if(n < 2) return 0;
    return n * (n - 1) / 2;
}

void solve(){
    int n; cin >> n;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    vi freq(1e6 + 1, 0);
    rep(i, n) {
        freq[arr[i]]++;
    }
    vi cnt(1e6 + 1, 0);
    f(i, 1, 1e6 + 1) {
        for(int j = i; j <= 1e6; j += i) {
            cnt[i] += freq[j];
        }
    }
    int ans = 0;
    vi mu = precompute(1e6);
    f(i, 1, 1e6 + 1) {
        ans += mu[i] * nC2(cnt[i]);
    }
    cout << ans << endl;
}
signed main(){
    fast;
    int tc;
    tc = 1;

    while(tc--){
        solve();
    }
    return 0;
}