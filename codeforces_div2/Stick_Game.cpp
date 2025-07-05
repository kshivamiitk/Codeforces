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

void solve(){
    int n , k;
    cin >> n >> k;
    vi arr(k);
    rep(i , k) cin >> arr[i];
    sort(all(arr));
    vvi dp(n + 1 , vi(2 , 0));
    rep(i , k){
        dp[arr[i]][0] = 1;
        dp[arr[i]][1] = 1;
    }
    f(i , 1 , n + 1){
        if(dp[i][0]) continue;
        // suppose 0 has a winning strategy for i, that means there exist any j
        // for which for i - arr[j] , 1 is going to loose, or
        // suppose 1 has a winning strategy for i , that means there exist any j
        // for which i - arr[j] , 0 is going to loose
        bool found = false;
        rep(j , k){
            if(i - arr[j] <= 0) break;
            if(!dp[i - arr[j]][0]){
                dp[i][0] = 1;
                dp[i][1] = 0;
                found = true;
                break;
            }
        }
        if(!found){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
    }
    f(i , 1 , n + 1){
        if(dp[i][0]) cout << "W" ;
        else cout << "L" ;
    }
    cout << endl;
}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc = 1;

    while(tc--){
        solve();
    }
    return 0;
}