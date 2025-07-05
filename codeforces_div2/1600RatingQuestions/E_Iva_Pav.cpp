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
bool possible(int n , int mid , vvi dp , int l , int k){
    
    // need to find if there exists such mid where f(l , mid) >= k
    
    //cout << "case 3" << endl;
    return true;
}
signed main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n ; cin >> n;
        vi arr(n);
        rep(i , n) cin >> arr[i];
        vvi dp(n+1 , vi(30 , 0));
        f(i , 1 , n+1){
            int x = arr[i-1];
            rep(j , 30){
                if(x & 1 << j) dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = dp[i-1][j];
            }
        }

        int q; cin >> q;
        // cout <<"print " << endl;
        // rep(i , n){
        //     rep(j , 30){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        while(q--){
            int l , k ; cin >> l >> k;
            int high = n , low = l;
            int ans = -1;
            while(low <= high){
                int mid = (low + high)/2;
                bool found = true;
                for(int i = 29 ; i >= 0 ; i--){
        // if the ith bit is set in k , but is not set in f(l , mid) return false
        if((1 << i) & k){
            //cout << "case 1" << endl;

            if(dp[mid][i] - dp[l-1][i] != mid - l + 1){
                found = false;
                break;
            }
        }
        if(!((1 << i) & k)){
            // means the current bit is not set, but if this is set in th
           // cout <<" case 2" << endl;
            if(dp[mid][i] - dp[l-1][i] == mid - l + 1) {
                found = true;
                break;
            }
            
        }
    }
                if(found){
                    ans = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            cout << ans <<" ";
        }
        cout << endl;
    }
    return 0;
}