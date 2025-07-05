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

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    // 1) compute L[i], R[i]
    vector<int> L(n, -1), R(n, -1);
    {   // nearest greater on left
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[st.top()] <= a[i]) 
                st.pop();
            if(!st.empty()) 
                L[i] = st.top();
            st.push(i);
        }
    }
    {   // nearest smaller on right
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && a[st.top()] >= a[i]) 
                st.pop();
            if(!st.empty()) 
                R[i] = st.top();
            st.push(i);
        }
    }

    // 2) build directed graph and its reverse
    vector<vector<int>> g(n), gr(n);
    for(int i = 0; i < n; i++){
        if(L[i] != -1){
            g[i].push_back(L[i]);
            gr[L[i]].push_back(i);
        }
        if(R[i] != -1){
            g[i].push_back(R[i]);
            gr[R[i]].push_back(i);
        }
    }

    // 3) Kosaraju: 1st pass order
    vector<char> vis(n,false);
    vector<int> order;
    order.reserve(n);
    // iterative DFS to avoid stack-overflow
    for(int start=0; start<n; start++){
        if(vis[start]) continue;
        stack<pair<int,int>> dfs;
        dfs.emplace(start, 0);
        while(!dfs.empty()){
            auto &[u, idx] = dfs.top();
            if(idx == 0){
                vis[u] = true;
            }
            if(idx < (int)g[u].size()){
                int v = g[u][idx++];
                if(!vis[v]){
                    dfs.emplace(v, 0);
                }
            } else {
                order.push_back(u);
                dfs.pop();
            }
        }
    }

    // 4) Kosaraju: 2nd pass on reverse graph, assign compIds
    vector<int> compId(n, -1);
    int compCount = 0;
    for(int i = n-1; i >= 0; i--){
        int u = order[i];
        if(compId[u] != -1) continue;
        // flood-fill this SCC
        stack<int> st; 
        st.push(u);
        compId[u] = compCount;
        while(!st.empty()){
            int x = st.top(); st.pop();
            for(int y: gr[x]){
                if(compId[y] == -1){
                    compId[y] = compCount;
                    st.push(y);
                }
            }
        }
        compCount++;
    }

    // 5) for each SCC compute base-max
    vector<int> baseMax(compCount, 0);
    for(int i = 0; i < n; i++){
        int c = compId[i];
        baseMax[c] = max(baseMax[c], a[i]);
    }

    // 6) build condensed DAG and compute dp in reverse topo
    vector<vector<int> > dag(compCount);
    vector<int> indeg(compCount, 0);
    for(int u = 0; u < n; u++){
        for(int v: g[u]){
            int cu = compId[u], cv = compId[v];
            if(cu != cv){
                dag[cu].push_back(cv);
                indeg[cv]++;
            }
        }
    }
    // Kahn’s topo
    queue<int> q;
    for(int c = 0; c < compCount; c++){
        if(indeg[c] == 0) 
            q.push(c);
    }
    vector<int> topo;
    topo.reserve(compCount);
    while(!q.empty()){
        int c = q.front(); q.pop();
        topo.push_back(c);
        for(int w: dag[c]){
            if(--indeg[w] == 0) 
                q.push(w);
        }
    }

    // dp[c] = max reachable height from any node in SCC c
    vector<int> dp = baseMax;
    // process in **reverse** topological order so that
    // when we handle c, all its successors have been done
    for(int ix = (int)topo.size() - 1; ix >= 0; ix--){
        int c = topo[ix];
        for(int w: dag[c]){
            dp[c] = max(dp[c], dp[w]);
        }
    }

    // 7) output
    for(int i = 0; i < n; i++){
        cout << dp[ compId[i] ] 
             << (i+1<n ? ' ' : '\n');
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) 
        solve();
    return 0;
}