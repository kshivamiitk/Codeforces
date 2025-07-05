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
struct node{
    int parent , val , col , white, black ;
};
void dfs(int start , int parent , vector<node>&arr , vi &visited , vvi tree , int&count){
    // update the parent
    visited[start] = true;
    for(auto neigh : tree[start]){
        if(neigh == parent) continue;
        if(!visited[neigh]){
            dfs(neigh , start , arr , visited, tree , count);
            arr[start].white += arr[neigh].white;
            arr[start].black += arr[neigh].black;
        }
    }
    arr[start].white += (arr[start].col == 0) ;
    arr[start].black += (arr[start].col == 1) ;
    if(arr[start].white == arr[start].black) count++;
}
void solve(){
    int n; cin >> n ;
    vector<node> arr(n);
    vvi tree(n);
    rep(i , n){
        // arr[i] tells the parent of i
        cin >> arr[i].parent ;
        
        arr[i].parent--;
        //tree[i].pb(arr[i].parent);
        tree[arr[i].parent].pb(i);
        arr[i].val = i ;
    }
    string s; cin >> s;
    rep(i , n){
        s[i] == 'W' ? arr[i].col = 0 : arr[i].col = 1;
    }
    vi visited(n , false);
    int count = 0;
    dfs(0 , 0 , arr, visited, tree , count);
    cout << count << endl;
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