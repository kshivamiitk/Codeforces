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
#define f(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,n) for(int i=0; i<(n); i++)
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

struct seg {
    int l, r, index;
};

bool cmp(seg a, seg b) {
    if(a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}

void solve() {
    int n;
    cin >> n;
    vector<seg> lines(n);
    rep(i, n) {
        cin >> lines[i].l >> lines[i].r;
        lines[i].index = i;
    }
    sort(all(lines), cmp);
    
    int last = lines[0].r;
    vector<seg> two;
    vi marks(n, 1);
    
    f(i, 1, n) {
        if (lines[i].l > last) {
            last = lines[i].r;
            marks[lines[i].index] = 1;
        } else {
            two.pb(lines[i]);
            marks[lines[i].index] = 2;
        }
    }
    
    // Check if the segments in group two are non-overlapping.
    last = LLONG_MIN;
    rep(i, sz(two)) {
        if (two[i].l <= last) {
            cout << -1 << endl;
            return;
        } else {
            last = two[i].r;
        }
    }
    
    rep(i, n) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

signed main() {
    fast;
    int tc;
    cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}
