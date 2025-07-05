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

int modexp(int a, int b) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> fact, invfact;
void precomp(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[n] = modexp(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}
struct edge{
    int a , b , w;
};
bool cmp(edge e1 , edge e2){
    return e1.w < e2.w;
};
struct DSU{
    int n ;
    vector<edge>edges;
    vi leader;
    int minimal;
    int maxWeight;
    int minWeight;
    int added;
    DSU(int m): n(m){
        leader.resize(m + 1);
        iota(all(leader) , 0);
        maxWeight = LLONG_MIN;
        minWeight = LLONG_MAX;
        added = 0;
    }
    void sortEdges(){
        sort(all(edges) , cmp);
    }
    int get(int a){
        if(a != leader[a]) leader[a] = get(leader[a]);
        return leader[a];
    }
    void add(edge Edge){
        int a = Edge.a;
        int b = Edge.b;
        a = get(a);
        b = get(b);
        if(a != b){
            if(a < b) swap(a , b);
            leader[b] = a;
            int currWeight = Edge.w;
            maxWeight = max(maxWeight , currWeight);
            minWeight = min(minWeight , currWeight);
            added++; 
        }
    }
    
    void reconfig(){
        iota(all(leader) , 0);
        maxWeight = LLONG_MIN;
        minWeight = LLONG_MAX;
        added = 0;
    }
};
void solve(){
    int n , m;
    cin >> n >> m;
    DSU dsu(n);
    rep(i , m){
        edge e;
        cin >> e.a >> e.b >> e.w;
        dsu.edges.pb(e);
    }
    dsu.sortEdges();
    int ans = LLONG_MAX;
    bool found = false;
    rep(i , m){
        dsu.reconfig();
        f(j , i , m){
            edge e = dsu.edges[j];
            dsu.add(e);
            if(dsu.added == n-1){
                ans = min(ans , dsu.maxWeight - dsu.minWeight);
                found = true;
                break;
            }
        }
    }
    if(found){
        cout << "YES" << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }
}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
