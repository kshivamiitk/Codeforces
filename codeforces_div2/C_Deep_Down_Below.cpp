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
bool cmp(vi arr , vi brr){
    int curr = LLONG_MIN;
    rep(i , sz(arr)){
        curr = max(curr , arr[i] - i);
    }
    int burr = LLONG_MIN;
    rep(i , sz(brr)){
        burr = max(burr , brr[i] - i);
    }
    return curr < burr;
}
void solve(){
    int n ;
    cin >> n ;
    int ans = LLONG_MIN;
    vvi arr;
    rep(i , n){
        int x; cin >> x;
        vi temp;
        rep(j , x){
            int y ; cin >> y;
            temp.pb(y);
        }
        arr.pb(temp);
    }
    //now sort the arrays in whom you need minm amt of moves to win
    sort(all(arr), cmp);
    int curr = 0;
    rep(i , arr.size()){
        vi x = arr[i];
        // take the current array as x and find the cost for it
        rep(j , x.size()){
           // cout << x[j] << " ";
            ans = max(ans , x[j] + 1 - j - curr);
        }
        curr += x.size();
        //cout << endl;
    }
    cout << ans << endl;
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