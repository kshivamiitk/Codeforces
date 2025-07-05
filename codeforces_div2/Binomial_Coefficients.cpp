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
vi fact(int n , int m){
    // return the fact[i] % m from 0 to n 
    vi factor(n + 1 , 1);
    f(i , 2 , n + 1){
        factor[i] = (i * factor[i-1]) % m;
    }
    return factor;
}
int power(int b , int e , int m){
    if(e == 0) return 1;
    if(e == 1) return b % m;
    int x = power(b , e/2 , m) ;
    if(e % 2){
        return (((x * x) % m) * b )% m;
    }
    return (x * x) % m ;
}
int inv(int n , int m){
    return power(n , m - 2 , m);
}
vi invfact(int n , int m){
    vi factor = fact(n , m);
    vi invfact(n + 1 , 1);
    rep(i , n + 1){
        invfact[i] = inv(factor[i] , m);
    }
    return invfact;
}
signed main(){
    fast;
    int tc;
    cin >> tc;
    vi factor = fact(1e6 + 1 , mod);
    vi invfactor = invfact(1e6 + 1 , mod);
    while(tc--){
        int a , b;
        cin >> a >> b;
        int ans = factor[a] % mod;
        ans = (ans * invfactor[b]) % mod;
        ans = (ans * invfactor[a - b]) % mod;
        cout << ans << endl;
    }
    return 0;
}