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
void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vi pos(n + 1, -1);
    rep(i, n) pos[a[i]] = i;
    vi frr(n);
    rep(i, n) frr[i] = pos[b[i]];
    rep(i, n){
        if(b[frr[i]] != a[i]){
            cout << -1 << endl;
            return;
        }
    }
    vector<bool> used(n, false);
    vpi mpairs;
    int fixedpt = -1;
    rep(i, n){
        if(!used[i]){
            if(frr[i] == i){
                if(fixedpt == -1) fixedpt = i;
                else { cout << -1 << endl; return; }
                used[i] = true;
            }
            else {
                int j = frr[i];
                if(used[j]) continue;
                int x = i, y = j;
                if(x > y) swap(x, y);
                mpairs.pb(mp(x, y));
                used[x] = used[y] = true;
            }
        }
    }
    if(n % 2 == 0 && fixedpt != -1){ cout << -1 << endl; return; }
    if(n % 2 == 1 && fixedpt == -1){ cout << -1 << endl; return; }
    vi target(n, -1);
    int l = 0, r = n - 1;
    for (auto p : mpairs){
        target[l++] = p.first;
        target[r--] = p.second;
    }
    if(n % 2 == 1) target[l] = fixedpt;
    vi curr(n);
    rep(i, n) curr[i] = i;
    vpi ops;
    vi pos2(n);
    rep(i, n) pos2[i] = i;
    rep(i, n){
        if(curr[i] != target[i]){
            int j = pos2[target[i]];
            swap(curr[i], curr[j]);
            swap(pos2[curr[i]], pos2[curr[j]]);
            ops.pb(mp(i + 1, j + 1));
        }
    }
    cout << sz(ops) << endl;
    for (auto op : ops) cout << op.first << " " << op.second << endl;
}
 
signed main(){
    fast;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
