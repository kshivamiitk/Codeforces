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

bool cmp(vi a, vi b){
    return a.size() > b.size();
}

void solve(){
    int n; cin >> n;
    MAP freq;
    vi team(n);
    rep(i, n){
        cin >> team[i];
        freq[team[i]]++;
    }
    vi temp;
    for(auto x : freq) temp.pb(x.ff);
    sort(all(temp));
    MAP locate;
    rep(i, sz(temp)) locate[temp[i]] = i;
    rep(i, n) team[i] = locate[team[i]];
    int c = sz(temp);
    vvi groups(c);
    vi arr(n);
    rep(i, n){
        cin >> arr[i];
        groups[team[i]].pb(arr[i]);
    }
    rep(i, c){
        sort(all(groups[i]), greater<int>());
        for(int j = 1; j < sz(groups[i]); j++){
            groups[i][j] = (groups[i][j] + groups[i][j-1]);
        }
    }
    vi res(n+1, 0);
    for(auto &g : groups){
        int s = sz(g);
        for(int k = 1; k <= s; k++){
            int full = s / k;
            res[k] = (res[k] + g[full*k - 1]);
        }
    }
    f(i, 1, n+1) cout << res[i] << " ";
    cout << endl;
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
