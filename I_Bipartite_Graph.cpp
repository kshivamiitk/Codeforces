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
struct DSU{
    int n ;
    vi parent , parity , size;
    DSU(int m): n(m){
        parent.resize(n + 1);
        iota(all(parent) , 0);
        parity.resize(n + 1 , 0);
        size.resize(n + 1 , 1);
    }
    pi find(int a){
        // this function is used to find the pairity as well as the parent of the current member
        if(parent[a] == a) return mp(a , 0);
        auto [r , p] = find(parent[a]);
        parity[a] ^= p;
        parent[a] = r;
        return mp( parent[r] , parity[a] );
    }
    void unite(int u , int v){
        auto [ru , pu] = find(u);
        auto [rv , pv] = find(v);
        if(size[ru] < size[rv]){
            parent[ru] = rv;
            parity[ru] = pu ^ pv ^ 1;
            size[rv] += size[ru];
        }else{
            parent[rv] = ru;
            parity[rv] = pu ^ pv ^ 1;
            size[ru] += size[rv];
        }
    }
};
void solve(){
    int n , m ;
    cin >> n >> m;
    DSU dsu(n);
    int shift = 0;
    rep(i , m){
        int x , y , z;
        cin >> x >> y >> z;
        int a = (shift + y) % n ;
        int b = (shift + z) % n;
        if(x == 0){
            dsu.unite(a , b);
        }else{
            auto [ra , pa] = dsu.find(a);
            auto [rb , pb1] = dsu.find(b);
            bool same = (ra == rb && pa == pb1);
            cout << (same ? "YES\n" : "NO\n");
            if(same) shift = (shift + 1) % n;
        }
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