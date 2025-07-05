#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i = 0; i < n; i++)
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
int dfs(int start , map<int,vi>&graph , vi &visited){
    visited[start] = 1;
    for(auto neigh : graph[start]){
        if(!visited[neigh]){
            return 1 + dfs(neigh , graph , visited);
        }
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    map<int, vi >graph;
    bool fault = false;
    rep(i , n){
        int x , y;
        cin >> x >> y;
        x--, y--;
        graph[x].pb(y);
        graph[y].pb(x);
        if(x == y || graph[x].size() > 2 || graph[y].size() > 2) fault = true;
    }
    if(fault){
        cout << "NO" << endl;
        return ;
    }
    vi visited(n , 0);
    rep(i , n){
        if(!visited[i]){
            if(dfs(i , graph , visited) % 2 == 1){
                cout << "NO" << endl;
                return ;
            }
        }
    }
    cout << "YES" << endl;

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
