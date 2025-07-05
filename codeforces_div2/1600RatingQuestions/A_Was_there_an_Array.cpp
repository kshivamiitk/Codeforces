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
signed main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n ; cin >> n ;
        vi arr(n , 0);
        bool found = false;
        f(i , 1 , n-1){
            int x ; cin >> x;
            arr[i] = x;
            
        }
        f(i , 1, n-1){
            if(arr[i] == 0){
                if(arr[i-1] == 1 && arr[i+1] == 1){
                    found = true;
                    break;
                }
            }
        }
        if(found) cout << "NO" << endl;
        else cout <<"YES" << endl;continue;
        vi brr(n , 0);
        f(i , 1 , n-1){
            if(arr[i] == 1){
                brr[i] = brr[i-1];
                brr[i+1] = brr[i];
                if(arr[i+1] == 0) i++;
            }else{
                brr[i] = brr[i-1] + 1;
            }
        }
        // printing the brr
        rep(i , n){
            cout << brr[i] << " ";
        }cout << endl;
        vi crr(n , 0);
        f(i , 1 , n-1){
            if(brr[i] == brr[i-1] && brr[i+1] == brr[i]){
                crr[i] = 1;
            }else{
                crr[i] = 0;
            }
        }
        rep(i , n){
            cout << crr[i] << " ";
        }cout << endl;
        // compare the arr and crr
        bool possible = true;
        rep(i , n){
            if(crr[i] != arr[i]){
                possible = false;
                break;
            }
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}