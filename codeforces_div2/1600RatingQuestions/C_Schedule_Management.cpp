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
bool possible(int time , vi arr , int m){
    int total = m;
    // total number of tasks needed to be done
    // arr[i] tells you the number of tasks alloted to person i
    int task = 0;
    rep(i , arr.size()){
        if(arr[i] >= time){
            task += time;

        }else{
            task += (arr[i] + (time - arr[i])/2);
        }
    }
    return total <= task;
}
signed main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n , m ; cin >> n >> m;
        vi arr(m);
        vi temp(n , 0);
        rep(i , m){
            cin >> arr[i];
            arr[i]--;
            temp[arr[i]]++;
        }
        int low = 1 , high = 1e9 ;
        int ans = -1;

        // rep(i , n) cout << temp[i] << " ";
        // cout << endl;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(mid , temp , m)){
                ans = mid ;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}