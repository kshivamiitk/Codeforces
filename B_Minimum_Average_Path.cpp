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
#include<iomanip>

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
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

bool possible(int n, vector<vpi>& temp, double mid, vi &par) {
    vector<vector<pair<int,double>>> graph(n);
    vi indeg(n, 0);
    rep(u,n) {
        for(auto x : temp[u]) {
            graph[u].pb({x.ff, x.ss - mid});
            indeg[x.ff]++;
        }
    }

    vector<double> dist(n, inf);
    par.assign(n, -1);
    dist[0] = 0;
    queue<int> q;
    rep(i,n) if(indeg[i]==0) q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto [v,w] : graph[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
            if(--indeg[v] == 0) q.push(v);
        }
    }

    return dist[n-1] <= 0;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vpi> graph(n);
    double high = 0;

    rep(i,m){
        int x,y,c;
        cin >> x >> y >> c;
        x--, y--;
        graph[x].pb({y,c});
        high = max(high, (double)c);
    }

    double low = 0;
    vi par;
    rep(i,60){
        double mid = (low + high) / 2;
        if(possible(n, graph, mid, par)){
            high = mid;
        } else {
            low = mid;
        }
    }

    possible(n, graph, high, par);
    vi path;
    int curr = n-1;
    while(curr != -1){
        path.pb(curr+1);
        curr = par[curr];
    }
    reverse(all(path));
    cout << sz(path)-1 << endl;
    for(auto x : path) cout << x << " ";
    cout << endl;
}

signed main(){
    fast;
    int tc=1;
    while(tc--) solve();
    return 0;
}
