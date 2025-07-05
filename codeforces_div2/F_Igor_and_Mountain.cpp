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

int modAdd(int a, int b){ a %= mod; b %= mod; return (a+b)%mod; }
int modMul(int a, int b){ a %= mod; b %= mod; return (a*b)%mod; }

signed main(){
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n, m, d; cin >> n >> m >> d;
        vector<string> grid(n);
        rep(i, n) cin >> grid[i];
        vector<vi> holds(n+1);
        f(r,1,n+1){
            holds[r].clear();
            int row = r - 1;
            f(c,1,m+1){
                if(grid[row][c-1]=='X') holds[r].pb(c);
            }
            sort(all(holds[r]));
        }
        int L = (d*d - 1 >= 0 ? (int)floor(sqrt((long double)d*d - 1)) : 0);
        vector<vi> dp(n+1, vi(m+1, 0));
        // Process bottom row (r = n)
        {
            vi &H = holds[n];
            int k = sz(H);
            if(k == 0){ cout << 0 << endl; continue; }
            // For each hold position l in H, dp[n][l] = number of holds f in H with |H[i] - f| <= d.
            rep(i, k){
                int pos = H[i];
                int lo = lower_bound(all(H), pos - d) - H.begin();
                int hi = upper_bound(all(H), pos + d) - H.begin();
                dp[n][pos] = (hi - lo) % mod;
            }
        }
        // Process rows from n-1 downto 1
        for(int r = n-1; r >= 1; r--){
            vi &H = holds[r];
            int k = sz(H);
            if(k == 0){ fill(dp[r].begin(), dp[r].end(), 0); continue; }
            vector<int> dpNext(m+2, 0);
            for(int c = 1; c <= m; c++){
                dpNext[c] = dp[r+1][c] % mod;
            }
            for(int c = 1; c <= m; c++){
                dpNext[c] = (dpNext[c] + dpNext[c-1]) % mod;
            }
            vector<int> diff(k+1, 0);
            rep(i, k) {
                int f_val = H[i];
                int L_bound = max((int)1, f_val - L);
                int R_bound = min(m, f_val + L);
                int X = (dpNext[R_bound] - (L_bound - 1 >= 1 ? dpNext[L_bound - 1] : 0)) % mod;
                if(X < 0) X += mod;
                int lowIdx = lower_bound(all(H), f_val - d) - H.begin();
                int highIdx = upper_bound(all(H), f_val + d) - H.begin() - 1;
                if(lowIdx <= highIdx){
                    diff[lowIdx] = (diff[lowIdx] + X) % mod;
                    if(highIdx + 1 < k) {
                        diff[highIdx+1] = (diff[highIdx+1] - X) % mod;
                        if(diff[highIdx+1] < 0) diff[highIdx+1] += mod;
                    }
                }
            }
            int cur = 0;
            for(int i = 0; i < k; i++){
                cur = (cur + diff[i]) % mod;
                dp[r][H[i]] = (dp[r][H[i]] + cur) % mod;
            }
        }
        int ans = 0;
        for(auto pos : holds[1]) {
            ans = (ans + dp[1][pos]) % mod;
        }
        cout << (ans % mod + mod) % mod << endl;
    }
    return 0;
}
