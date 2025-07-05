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

// The solve() function implements the idea:
// 1. Convert x and y to binary strings (handling 0 properly).
// 2. Compute the longest common prefix (LCP) length.
// 3. Let d1 = (number of bits in x) - LCP and d2 = (number of bits in y) - LCP.
// 4. Use DP to choose a set S of distinct positive integers (operations) partitioned into two groups
//    (one summing to d1 and the other to d2) that minimizes the total cost sum_{k in S} 2^k.
void solve(){
    int x, y;
    cin >> x >> y;
    
    // Function to convert a number to its binary string (without leading zeros)
    auto toBinary = [&](int a) -> string {
         if(a == 0) return "0";
         string s = "";
         while(a > 0) {
              s.push_back((char)('0' + (a % 2)));
              a /= 2;
         }
         reverse(s.begin(), s.end());
         return s;
    };
    
    string xs = toBinary(x);
    string ys = toBinary(y);
    
    // Find longest common prefix (LCP)
    int lcp = 0;
    int l = min(xs.size(), ys.size());
    while(lcp < l && xs[lcp] == ys[lcp]) lcp++;
    
    int d1 = xs.size() - lcp; // extra bits to remove from x
    int d2 = ys.size() - lcp; // extra bits to remove from y
    
    // If both numbers already match, no cost is required.
    if(d1 == 0 && d2 == 0){
         cout << 0 << endl;
         return;
    }
    
    int d = d1 + d2; // total bits we need to remove
    // We will consider candidate operations with parameter k from 1 to M.
    // Since any k > d is useless (as it would remove more bits than needed),
    // we set M = d.
    int M = d;
    
    const ll INF = 1e18; // a sufficiently large number
    // dp[s1][s_total] = minimum cost to achieve that using some subset of {1,...,i}
    // where s1 is the bits removed from x (should sum to d1) and s_total is the total bits removed.
    vector<vector<ll> > dp(d1+1, vector<ll>(d+1, INF));
    dp[0][0] = 0;
    
    // For candidate operations from 1 to M:
    for (int i = 1; i <= M; i++){
         vector<vector<ll> > ndp(d1+1, vector<ll>(d+1, INF));
         for (int s1 = 0; s1 <= d1; s1++){
              for (int s_total = 0; s_total <= d; s_total++){
                   if(dp[s1][s_total] == INF) continue;
                   // Option 1: Skip candidate i (do not use operation with parameter i)
                   ndp[s1][s_total] = min(ndp[s1][s_total], dp[s1][s_total]);
                   
                   // Option 2: Use candidate i for x (add i bits to d1-group)
                   if(s1 + i <= d1 && s_total + i <= d){
                        ndp[s1+i][s_total+i] = min(ndp[s1+i][s_total+i], dp[s1][s_total] + (1LL << i));
                   }
                   
                   // Option 3: Use candidate i for y (add i bits to d2-group, s1 remains same)
                   if(s_total + i <= d){
                        ndp[s1][s_total+i] = min(ndp[s1][s_total+i], dp[s1][s_total] + (1LL << i));
                   }
              }
         }
         dp = ndp;
    }
    
    ll ans = dp[d1][d];
    cout << ans << endl;
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
