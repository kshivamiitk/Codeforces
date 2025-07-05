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
// #define sz(x) (int)x.size()
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

struct DSU {
    int n;
    vi parent, nxt;

    DSU(int m): n(m), parent(m+2), nxt(m+2) {
        iota(parent.begin(), parent.end(), 0);
        iota(nxt.begin(), nxt.end(), 0);
    }

    int get(int a) {
        if (parent[a] != a) parent[a] = get(parent[a]);
        return parent[a];
    }

    void merge(int a, int b) {
        a = get(a);
        b = get(b);
        if (a != b) parent[b] = a;
    }

    // Path-compressed next
    int findNext(int i) {
        if (nxt[i] != i) nxt[i] = findNext(nxt[i]);
        return nxt[i];
    }

    void greaterMerge(int x, int y) {
        for (int i = findNext(x); i < y; i = findNext(i)) {
            merge(i, i + 1);
            nxt[i] = i + 1;
        }
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    rep(i, m){
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            dsu.merge(x, y);
        }
        else if (type == 2) {
            dsu.greaterMerge(x, y);
        }
        else {
            cout << (dsu.get(x) == dsu.get(y) ? "YES" : "NO") << endl;
        }
    }
}

signed main(){
    fast;
    solve();
    return 0;
}
