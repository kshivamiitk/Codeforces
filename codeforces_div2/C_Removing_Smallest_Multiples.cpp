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
vi factorize(int n){
    // return the factors in sorted way
    vi ans ;
    for(int i = 1 ; i * i <= n ; i++){
        if(n % i == 0){
            if(i * i == n){
                ans.pb(i);
                sort(all(ans));
                return ans;
            }
            ans.pb(i);
            ans.pb(n / i);
        }
    }
    sort(all(ans));
    return ans;
}
void solve(){
    int n ; cin >> n;
    string s;
    cin >> s;
    vi exists(n + 1 , 0);
    vi changed(n + 1 , 0);
    rep(i , n){
        if(s[i] == '1'){
            exists[i+1]=1;
        }
    }
    int cost = 0;
    vector<int>freq(n+1 , 0);
    rep(i , n){
        int curr = i + 1;
        vi factors = factorize(curr);
        if(exists[curr]){
            rep(i , factors.size()){
                freq[factors[i]]++;
            }
        }else{
            for(int factor : factors){
                // check if the current factor has availablity or not
                if(freq[factor] == 0){
                    cost += factor;
                    break;
                }
            }
        }

    }
    cout << cost << endl;
}
signed main()
{
int tc;
cin >> tc;
while(tc--){
solve();
    }return 0;
}