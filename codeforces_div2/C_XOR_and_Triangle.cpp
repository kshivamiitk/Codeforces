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

void solve(){
    int n; 
    cin >> n;
    
   
    for(int i = 0; i < 32; i++){
        if(n == (1 << i)){
            cout << -1 << endl;
            return;
        }
    }
    
    
    int msb = 31 - __builtin_clz(n); // index of the most significant bit
    bool allOnes = true;
    for(int i = 0; i < msb; i++){
        if(((n >> i) & 1) == 0){
            allOnes = false;
            break;
        }
    }
    if(allOnes){
        cout << -1 << endl;
        return;
    }
    
    if(n % 2 == 0){
        cout << n - 1 << endl;
    }else {
        int x = n;
        msb = 63 - __builtin_clzll(x);
        int j = 1;
        while(j <= msb && ((x >> j) & 1LL))
        j++;
        int y = (1LL << j) | 1LL;
        cout << y << "\n";
    }
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