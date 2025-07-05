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
void dfs(int node , vvi &graph , vi &color , int c , vi &visited){
    visited[node] = true;
    color[node] = c;
    for(auto neigh : graph[node]){
        if(!visited[neigh]){
            dfs(neigh , graph , color , (c + 1)% 2 , visited);
        }
    }
}
void solve(){
    int n ;
    cin >> n;
    vvi graph(n);
    rep(i , n - 1){
        int u , v ; cin >> u >> v;
        u--, v--;
        graph[u].pb(v); graph[v].pb(u);
    }
    vi visited(n , false);
    vi color(n , -1);
    dfs(0 , graph , color , 0 , visited);
    vi first , second;
    rep(i , n){
        if(color[i] == 0) first.pb(i);
        else second.pb(i);
    }
    int possible = first.size() * second.size();
    cout << possible - (n-1) << endl;
}
signed main(){
    fast;
    int tc;
    tc  = 1;
    while(tc--){
        solve();
    }
    return 0;
}