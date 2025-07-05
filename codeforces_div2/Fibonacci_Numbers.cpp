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
vvi multiply(vvi a , vvi b){
    vvi c(2 , vi(2 , 0));
    c[0][0] = ((a[0][0] * b[0][0]) % mod + (a[0][1] * b[1][0])  % mod) % mod;
    c[0][1] = ((a[0][0] * b[0][1]) % mod + (a[0][1] * b[1][1]) % mod ) % mod;
    c[1][0] = ((a[1][0] * b[0][0]) % mod + (a[1][1] * b[1][0]) % mod ) % mod;
    c[1][1] = ((a[1][0] * b [0][1]) % mod + (a[1][1] * b[1][1]) % mod) % mod;
    return c;
}
vvi power(vvi a , int exp){
    if(exp == 0){
        vvi c(2 , vi(2 , 0));
        c[0][0] = 1, c[1][1] = 1;
        return c;
    }
    if(exp == 1){
        return a;
    }
    vvi x = power(a , exp/2);
    if(exp % 2){
        return multiply(x , multiply(x , a));
    }
    return multiply(x , x);
}
void solve(){
    int n; cin >> n;
    if(n == 0){ cout << 0 << endl; return; }
    vvi a(2 , vi(2 , 0));
    a[0][0] = a[0][1] = a[1][0] = 1;
    a[1][1] = 0;
    vvi res = power(a, n-1);
    cout << res[0][0] << endl;
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
