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


int nc2(int n) {
    return n * (n - 1) / 2;
}


int func(int n) {
    int m = 1;
    while(nc2(m) <= n) m++;
    return m - 1;
}


vi lelo(int n) {
    vi arr;
    while(n > 0) {
        int m = func(n);
        arr.pb(m);
        n -= nc2(m);
    }
    return arr;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;

        if(k == 0) {
            cout << 1 << endl;
            cout << 0 << " " << 0 << endl;
            continue;
        }
        vi arr = lelo(k);
        vpi points;
        int x = 0, y = 0;

        rep(i, sz(arr)){
            int cnt = arr[i];
            rep(j, cnt){
                points.pb(make_pair(x, y));
                y++; 
            }
            x++; 
        }
        cout << points.size() << endl;
        rep(i, sz(points)){
            cout << points[i].ff << " " << points[i].ss << endl;
        }
    }
    return 0;
}
