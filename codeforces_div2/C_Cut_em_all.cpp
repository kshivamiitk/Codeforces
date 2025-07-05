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
int dfs(int start , vvi &graph , vi &visited , vi &parent , vi &size){
    visited[start] = 1;
    int temp = 1;
    for(auto neigh : graph[start]){
        if(neigh == parent[start]) continue;
        if(!visited[neigh]){
            parent[neigh] = start;
            temp += dfs(neigh , graph , visited , parent , size);
        }
    }
    return size[start] = temp ; 
}

void solve(){
    int n; cin >> n;
    vvi graph(n);
    rep(i , n - 1){
        int u , v ;
        cin >> u >> v ;
        u-- , v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    if(n % 2 == 1){
        cout << -1 << endl;
        return ;
    }
    vi visited(n , 0);
    vi parent(n , 0);
    vi size(n , 0);
    dfs(0 , graph , visited , parent , size);
    int count = 0;
    f(i , 1 , n){
        if(size[i] % 2 == 0) count++;
    }
    cout << count << endl;
    return ;
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