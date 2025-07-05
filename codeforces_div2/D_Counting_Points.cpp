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
    int n , m;
    cin >> n >> m ;
    vi x(n);
    rep(i , n) cin >> x[i];
    vi radius(n);
    rep(i , n) cin >> radius[i];
    map<int , vpi > intervals;
    rep(i , n){
        // take the current radius and find the range of the 
        int center = x[i];
        int radii = radius[i];
        for(int y = - radii ; y <= radii ; y++){
            int rem = radii * radii - y * y;
            int d = (int)floor(sqrt(rem));
            intervals[y].pb(mp(center - d , center + d));
        }
    }
    int answer = 0;
    for(auto interval : intervals){
        // first need to sort the intervals on the basis of their startings
        vpi curr = interval.ss;
        sort(all(curr));
        int start = curr[0].ff , end = curr[0].ss;
        f(i , 1 , sz(curr)){
            int l = curr[i].ff , r = curr[i].ss;
            if(l <= end + 1){
                end = max(end , r);
            }else{
                answer += (end - start + 1);
                end = r;
                start = l;
            }
        }
        answer += (end - start + 1);
    }
    cout << answer << endl;
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