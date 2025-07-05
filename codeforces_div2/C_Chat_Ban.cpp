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
bool possible(int mid , int k , int x){
    // now check whether the mid can help you out in working
    if(mid <= k){
        int i =  mid * (mid + 1) / 2;
        int j = (mid - 1) * (mid)/2;
        return i <= x || (i >= x && j < x);
    }else{
        int message = k * (k + 1)/2;
        // check if I can write 
        int t = k - 1;
        t = t * (t + 1)/2;
        mid -= k;
        // check if the last mid, that is from k - 1 to k - mid + 1 could be made or not
        k -= mid ;
        message += t;
        message -= k * (k + 1)/2;
        return message <= x || (message >= x && message - k < x);
    }
}
void solve(){
    int k , x ;
    cin >> k >> x;
    // if(2 * k - 1 <= x){
    //     cout << 2 * k - 1 << endl;
    //     return ;
    // }
    // now you have to find the case whether you can write t messages or not
    int total = k * k ;
    if(x >= total){
        cout << 2 * k - 1 << endl;
        return;
    }
    int start = 1 , end = 2 * k - 1;
    int ans = 2 * k - 1;
    while(start <= end){
        int mid = (start + end)/2;
        int sum ;
        if(mid <= k){
            sum = (mid) * (mid + 1)/2;
        }else{
            int d = mid - k;
            sum = k * (k+1)/2 + d * k - d * (d + 1)/2;

        }
        if(sum >= x){
            ans = mid ;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
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