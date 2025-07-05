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



int processMax(int x, int n, int m) {
    if(x == 0) return 0;
    while ((n + m) > 0 && x >= 2) {
        if(x % 2 == 0) {
            if(n == 0) { x /= 2; m--; }
            else { x /= 2; n--; }
        } else {
            if(m > 0) { x = (x + 1) / 2; m--; }
            else { x = x / 2; n--; }
        }
    }
    if(x == 1 && (n + m) > 0) {
       return (n > 0 ? 0 : 1);
    }
    return x;
}


int processMin(int x, int n, int m) {
    if(x == 0) return 0;
    while ((n + m) > 0 && x >= 2) {
        if(x % 2 == 0) {

            if(m > 0) { x /= 2; m--; }
            else { x /= 2; n--; }
        } else {

            if(n > 0) { x = x / 2; n--; }
            else { x = (x + 1) / 2; m--; }
        }
    }

    if(x == 1 && (n + m) > 0) {
       return (n > 0 ? 0 : 1);
    }
    return x;
}
 
signed main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        int x, n, m;
        cin >> x >> n >> m;

        if(x == 0) {
            cout << "0 0" << "\n";
            continue;
        }

        int mn = processMin(x, n, m);
        int mx = processMax(x, n, m);
        cout << mn << " " << mx << "\n";
    }
    return 0;
}
