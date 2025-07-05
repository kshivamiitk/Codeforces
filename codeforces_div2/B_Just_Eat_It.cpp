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
    int n; cin >> n;
    // find the the subarray which has the max sum, how shall you even do it
    // like dp[i] should tell me the maximum sum if I am taking the current one as the last element
    // dp[i] = dp[i-1] + arr[i] if arr[i] + dp[i-1] > arr[i] else arr[i] only
    vi arr(n);
    rep(i , n) cin >> arr[i];

    vi dp(n , 0);
    // dp[i] tells maximum taste you can get if you take the arr[i]
    int count = 0;
    rep(i , n-1){
        if(dp[i] > 0){
            dp[i + 1] = arr[i] + dp[i];
            count++;
        }else{
            dp[i + 1] = arr[i];
            count = 1;
        }
    }
    // rep(i , n+1) cout << dp[i] << " " ;
    // cout << endl;
    int total = accumulate(all(arr) , 0LL);
    // if all the array is full of positive integer, or it the total is nothing but sum of all then 
    int maxm = *max_element(all(dp));
    vi dp1(n + 1 , 0);
    f(i , 1 , n){
        if(dp1[i] > 0){
            dp1[i+1] = arr[i] + dp1[i];
        }else{
            dp1[i+1] = arr[i];
        }
    }
    maxm = max(maxm , *max_element(all(dp1)));
    // I have to monitor that there is no such case where the

    //cout << maxm << endl;
    if(total > maxm){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}