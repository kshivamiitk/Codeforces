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
bool possible(int r , int a , int b , int mid){
    if(a * mid - b < 0) return false;
    return r >= a * mid - b ;
}
void solve(){
    string s;
    cin >> s;
    int cb = 0 , cs = 0 , cc = 0;
    rep(i , s.size()){
        if(s[i] == 'B')cb++;
        if(s[i] == 'C')cc++;
        if(s[i] == 'S')cs++;
    }
    int nb, ns, nc;
    int pb, ps , pc, r;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    int a = pb * cb + ps *cs + pc * cc;
    int b = pb * nb + pc * nc + ps * ns;
    auto cost_for = [&](int mid){
        int b = max(0LL , cb * mid - nb);
        int s = max(0LL , cs * mid - ns);
        int c = max(0LL , cc * mid - nc);
        return b * pb + s * ps + c * pc;
    };
    int low = 0 , high = 1e15;
    int ans = low;
    while(low <= high){
        int mid = (low + high)/2;
        if(cost_for(mid) <= r){
            ans = mid ;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
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