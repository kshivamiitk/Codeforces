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
#include <iomanip>

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
#define inf 1000000000
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

void solve(){
    int n, s;
    cin >> n >> s;
    vi arr(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(s+1, 0), old;
    dp[0] = 1;  

    int answer = inf;
    for(int r = 1; r <= n; r++){
        old = dp;
        int x = arr[r];
        dp[x] = max(dp[x], r);
        for(int j = s; j > x; j--){
            if(old[j - x] != 0){
                dp[j] = max(dp[j], old[j - x]);
            }
        }
        if(dp[s] != 0){
            answer = min(answer, r - dp[s] + 1);
        }
    }

    if(answer == inf) 
        cout << -1 << endl;
    else 
        cout << answer << endl;
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
