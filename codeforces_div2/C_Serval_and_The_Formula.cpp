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
#include<cstring>

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

const int B = 62;
int dp[B+1][2][2];
bool vis[B+1][2][2];

int rec(int pos, int c, int d, ll x, ll y) {
    if(pos == B) {
        return (c == 0 && d == 0) ? 0 : -1;
    }
    if(vis[pos][c][d]) return dp[pos][c][d];
    int ans = -1;
    for(int b = 0; b < 2; b++){
        int X = (x >> pos) & 1LL;
        int Y = (y >> pos) & 1LL;
        int s1 = X + b + c;
        int a = s1 & 1;
        int nc = s1 >> 1;
        int s2 = Y + b + d;
        int bit = s2 & 1;
        int nd = s2 >> 1;
        if(a == 1 && bit == 1) continue;
        int ret = rec(pos + 1, nc, nd, x, y);
        if(ret != -1) {
            ans = ret | (b << pos);
            break;
        }
    }
    vis[pos][c][d] = true;
    dp[pos][c][d] = ans;
    return ans;
}

void solve(){
    ll x, y;
    cin >> x >> y;
    memset(vis, 0, sizeof(vis));
    int res = rec(0, 0, 0, x, y);
    cout << res << endl;
}

signed main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
