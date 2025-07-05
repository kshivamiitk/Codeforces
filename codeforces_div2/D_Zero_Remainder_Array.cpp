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
    int n , k;
    cin >> n >> k;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    MAP freq;
    rep(i , n){
        int curr = arr[i] % k;
        if(curr == 0){
            arr[i] = 0;
            continue;
        }
        
        arr[i] = k - curr + freq[curr] * k ;
        freq[curr]++;
        // this is the curr required to be added to it in order to make it divisible by k
    }
    sort(all(arr));
    // rep(i , n) cout << arr[i] << " " ;
    // cout << endl;
    // here we are going to increase
    int x = 0;
    int ans = 0;
    rep(i , n){
        if(arr[i] == 0) continue;
        ans += (arr[i] - x + 1);
        x = arr[i] + 1;
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