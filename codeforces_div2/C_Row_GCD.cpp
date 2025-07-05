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
int gcd(int a , int b){
    if(b == 0) return a;
    //if(a % b == 0) return b;
    return gcd(b , a % b);
}
void solve(){
    int n , m;
    cin >> n >> m;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    sort(all(arr));
    vi brr(m);
    rep(i , m) cin >> brr[i];
    if(n == 1){
        rep(i , m) cout << arr[0] + brr[i] << " ";
        cout << endl;return ;
    }
    vi temp;
    f(i , 1,  n){
        temp.pb(arr[i] - arr[0]);
    }
    int g = temp[0];
    
    f(i , 1 , temp.size()){
        g = gcd(g , temp[i]);
    }
    //cout << g << endl;
    // rep(i , factors.size()){
    //     cout << factors[i] << " ";
    // }
    // cout << endl;
    rep(i , m){
        int ans = gcd(arr[0] + brr[i] , g);
        cout << ans << " ";
    }
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