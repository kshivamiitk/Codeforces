#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>

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

struct ANS {
    int k;
    vi arr;
};

int n, m, d;
vector<vpi> graph;
ANS ans_mid;          // will hold the answer path
vector<int> parent_g; // for BFS parent pointers

// Check via BFS whether there is a path from 0 to n-1 of <= d edges
// using only edges of cost <= mid.
bool possible(int n , int m , int d , vector<vpi>& graph , int mid) {
    vector<int> dist(n, INT_MAX);
    parent_g.assign(n, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] == d) continue;  // already used up d edges
        for (auto &e : graph[u]) {
            int v = e.ff, w = e.ss;
            if (w > mid) continue;     // skip too‑large edges
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent_g[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n-1] <= d) {
        // populate ans_mid here to avoid re‑running BFS later
        vi path;
        for (int cur = n-1; cur != -1; cur = parent_g[cur])
            path.pb(cur+1);        // convert to 1‑based
        reverse(all(path));
        ans_mid.k   = sz(path) - 1;  // number of edges
        ans_mid.arr = path;
        return true;
    }
    return false;
}

// We no longer need a separate populate(...) since possible()
// already fills ans_mid. We leave the stub here to match your
// signature, but it won't be called.
void populate(int n , int m , int d , vector<vpi>& graph , int mid , ANS &ans) {
    // unused
}

void solve(){
    cin >> n >> m >> d;
    graph.assign(n, {});
    int maxC = 0;

    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        graph[a].pb({b, c});
        maxC = max(maxC, c);
    }

    int low = 0, high = maxC;
    int best = -1;

    while (low <= high) {
        int mid = (low + high) >> 1;
        if (possible(n, m, d, graph, mid)) {
            best = mid;
            high = mid - 1;   // try to find a smaller maximum edge
        } else {
            low = mid + 1;
        }
    }

    if (best < 0) {
        cout << -1 << endl;
    } else {
        // possible(...) already filled ans_mid
        cout << ans_mid.k << "\n";
        for (int x : ans_mid.arr) 
            cout << x << " ";
        cout << "\n";
    }
}

signed main(){
    fast;
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
