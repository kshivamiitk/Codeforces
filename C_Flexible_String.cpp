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
int count(int n){
    int c = 0;
    rep(i , 32){
        if((1 << i) & n) c++;
    }
    return c;
}
void solve(){
    int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        set<char> s;
        rep(i, n) s.insert(a[i]);
        vector<char> distinct(s.begin(), s.end());
        int m = distinct.size();
        if(k >= m){
            cout << n*(n+1)/2 << "\n";
            // continue; 
            return ;
        }
        vector<int> charIndex(256, -1);
        rep(i, m){
            charIndex[distinct[i]] = i;
        }
        int ans = 0;
        int totalMasks = 1LL << m;
        for(int mask = 0; mask < totalMasks; mask++){
            if(__builtin_popcountll(mask) > k) continue;
            int total = 0, cnt = 0;
            rep(i, n){
                bool match = (a[i] == b[i]);
                if(!match){
                    int idx = charIndex[a[i]];
                    if(idx != -1 && (mask & (1LL << idx)))
                        match = true;
                }
                if(match)
                    cnt++;
                else{
                    total += cnt*(cnt+1)/2;
                    cnt = 0;
                }
            }
            total += cnt*(cnt+1)/2;
            ans = max(ans, total);
        }
        cout << ans << "\n";
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