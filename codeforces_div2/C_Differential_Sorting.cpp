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
    int n ; cin >> n ;
    
    vi arr(n);
    rep(i , n){
        cin >> arr[i];
    }
    vi x = arr;
    sort(all(x));
    int count = 0;
    rep(i , n){
        if(x[i] == arr[i]) count++;
    }
    if(count == n){
        // means this is already sorted no need to further interact
        cout << 0 << endl;
        return ;
    }
    // if(arr[n-1] <= 0){
    //     // if the last one is negative and there are atleast one positive inside, nothing could be done to save this out
    //     cout << -1 << endl;
    //     return ;
    // }
    vi ans(n);
    rep(i , n-2){
        ans[i] = arr[n-2] - arr[n-1];
    }
    ans[n-2] = arr[n-2];
    ans[n-1] = arr[n-1];
    // rep(i , n){
    //     cout << ans[i] << " ";
    // }cout << endl;
    vi temp = ans;
    sort(all(temp));
    rep(i , n){
        if(temp[i] != ans[i]){
            cout << -1 << endl;
            return ;
        }
    }
    cout << n-2 << endl;
    rep(i , n-2){
        cout << i + 1 <<" " << n-1 << " " << n << endl;
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