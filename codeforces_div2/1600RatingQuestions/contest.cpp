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
signed main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n ; cin >> n;
        vi arr(n);
        rep(i , n) cin >> arr[i];
        vvi dp(n , vi(2 , 0));
        if(arr[0] == 0){
            dp[0][0] = 1;
            dp[0][1] = 1;
        }else{
            dp[0][1] = 0;
            dp[0][0] = 1;
        }
        for(int i = 1 ; i < n ; i++){
            dp[i][0] = dp[i-1][1];
            if(arr[i] > (i+1)/2){
                dp[i][1] = 0;// means i is a liar for sure, so i-1 should be honest
            }else{
                // here I am assuming that i is dishonest
                if(arr[i] == (i+1)/2){
                    if(i%2==1){
                        dp[i][1] = dp[i-1][0];
                    }else{
                        if(arr[i-1] == arr[i]){
                            // means i-1 can or cannot be honest
                            dp[i][1] = dp[i-1][1];
                            if(i-2 >=0 && arr[i-2] + 1 == arr[i]){
                                dp[i][1] += dp[i-2][1];
                            }

                        }else{
                            if(i-2 >=0 && arr[i-2] + 1 == arr[i]){
                                dp[i][1] = dp[i-2][1];
                            }else{
                                dp[i][1] = 0;
                            }
                        }
                    }
                    continue;
                }
                if(arr[i] == 0){
                    // means there are no liars
                    dp[i][1] = 1;
                    continue;
                }else{
                    if(arr[i-1] == arr[i]){
                        // means i-1 has to be honest
                        dp[i][1] = dp[i-1][1];
                        if(i-2 >=0 && arr[i-2] + 1 == arr[i]){
                                dp[i][1] += dp[i-2][1];
                        }
                    }else{
                        if(i-2 >=0 && arr[i-2] + 1 == arr[i]){
                                dp[i][1] = dp[i-2][1];
                            }else{
                                dp[i][1] = 0;
                        }
                    }
                }
            }
        }
        // print the whole dp
        // rep(i , n){
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        // }
        cout << dp[n-1][1] + dp[n-1][0] << endl;
    }
    return 0;
}