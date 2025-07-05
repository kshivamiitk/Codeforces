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
void dfs(int start , vvi &graph , vi &visited , vi &group , int count){
    visited[start] = 1;
    group[start] = count;
    for(auto neigh : graph[start]){
        if(!visited[neigh]){
            dfs(neigh, graph , visited , group , count);
        }
    }
}
void solve(){
    int n , m;
    cin >> n >> m;
    vvi graph(n);
    rep(i , m){
        int k ;
        cin >> k;
        vi temp(k);
        rep(i , k) {cin >> temp[i]; temp[i]--; }
        rep(i , k - 1){
            graph[temp[i]].pb(temp[i+1]);
            graph[temp[i+1]].pb(temp[i]);
        }
        int curr = LLONG_MIN;

    }
    vi group(n , 0);
    vi visited(n , 0);
    int c = 0;
    rep(i , n){
        if(!visited[i]){
            dfs(i , graph , visited , group , c);
            c++;
        }
    }
    vi count(c , 0);
    rep(i , n){
        count[group[i]]++;
    }
    rep(i , n){
        cout << count[group[i]] << " " ;
    }
    cout << endl;

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