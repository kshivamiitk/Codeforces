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
void dfs(int start , vvi &graph , vi &parent , vector<bool> &visited , vi &count , map<pi , int>&dp){
    visited[start] = true;
    for(auto neigh : graph[start]){
        if(!visited[neigh]){
            parent[neigh] = start;
            int ppi = parent[start];
            int p = start;
            int i = neigh;
            if(dp[mp(ppi , p)] < dp[mp(p , i)]){
                count[i] = min(count[i] , count[p]);
            }
            else{
                count[i] = min(count[i] , count[p] + 1);
            }
            dfs(neigh , graph , parent , visited , count , dp);
        }
    }
}
void solve(){
    int n ; cin >> n ;
    vvi graph(n);
    map<pi , int>dp;
    dp[mp(0 , 0)] = -1;
    rep(i , n - 1){
        int u , v; cin >> u >> v;
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
        dp[mp(u , v)] = i;
        dp[mp(v , u)] = i;
    }
    vi parent(n , -1);
    parent[0] = 0;
    vector<bool> visited(n , false);
    vi count(n , LLONG_MAX);
    count[0] = 1;
    dfs(0 , graph , parent , visited , count , dp);
    
    cout << *max_element(all(count)) << endl;
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