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

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
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

// Fast modular exponentiation.
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    map<pi, int> freq;
    int zeros = 0;  
    rep(i, n){
        cin >> b[i];
        if(a[i] == 0 && b[i] == 0){
            zeros++;
            continue;
        }
        if(a[i] == 0){
            continue;
        }
        int x1 = abs(a[i]);
        int y1 = abs(b[i]);
        int g = gcd(x1, y1);
        if(g != 0){
            x1 /= g;
            y1 /= g;
        }
        int sign = (a[i] * b[i] < 0 ? -1 : 1);
        freq[mp(sign * x1, y1)]++;
    }
    
    int maxm = 0;
    for(auto &x : freq){
        maxm = max(maxm, x.second);
    }
    int ansGroups = 0;
    for(auto &x : freq){
        if(x.second == maxm){
            ansGroups++;
        }
    }

    cout << zeros + maxm << endl;
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
