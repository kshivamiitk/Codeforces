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
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
#define mod 1000000007
#define mod1 1000000009
#define mod2 998244353
#define mod3 1000000007
#define mod4 1000000009
#define mod5 1000000021
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
int BS(const vi &psum, int left, int target){
    // first the smallest right such that we can have psum
    int n = psum.size() - 1;
    if(psum[n] - psum[left-1] < target){
        return LLONG_MAX;//means I dont have the target achievable
    }
    int low = left - 1, high = n;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(psum[mid] - psum[left-1] == target){
            ans = mid;
            low = mid + 1;
            // I need to return the maxm mid such that I can get the desired target
        }
        else if(psum[mid] - psum[left-1] > target){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    //cout << ans << endl;
    return ans;
}
void solve(){
    int n ; cin >> n ;
    int s ; cin >> s;
    vi arr(n);
    rep(i ,n) cin >> arr[i];
    vi psum(n + 1);
    psum[0]= 0;
    rep(i , n){
        psum[i+1] = psum[i] + arr[i];
        //cout << psum[i+1]<<" ";
    }
    //cout << endl;
    // using binary search find the smallest r such that psum[r] - psum[l-1] == s
    int ans = LLONG_MIN;
    rep(i , n){
        if(BS(psum , i + 1 , s) == LLONG_MAX){
            continue;
        }
        ans = max(ans , BS(psum , i + 1 , s) - i);
    }
    if(ans == LLONG_MIN){
        cout << -1 << endl;
        return ;
    }
    cout << n - ans << endl;
}
signed main()
{
int tc;
cin >> tc;
while(tc--){
solve();
    }return 0;
}