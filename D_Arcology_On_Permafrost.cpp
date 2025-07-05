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
    int n, m, k;
        cin >> n >> m >> k;
        vi a(n, 0);
        int c1 = n / (m + 1);
        if(c1 >= k){
            int X = c1;
            rep(i , n){
                a[i] = i % X;
            }
        } else {
            int X = n / (1 + m * k);
            rep(i , n){
                a[i] = X; 
            }
            rep(x , X){
                rep(j , m + 1){
                    int pos = j * k + x;
                    if(pos < n){
                        a[pos] = x;
                    }
                }
            }
        }
        rep(i , n){
            cout << a[i] << " ";
        }
        cout << "\n";
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
