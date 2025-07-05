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
signed main()
{
    int n , x;
    cin>>n>>x;
    vi prices(n) , pages(n);    
    rep(i , n){
        cin>>prices[i];
    }
    rep(i , n){
        cin>>pages[i];
    }
    vvi dp(n+1 , vi(x+1));
    dp[0][0] = 0;
    f(i , 1, n+1){
        f(j , 0 , x+1){
            int taken = 0;
            if(j >= prices[i-1]){
                taken = dp[i-1][j-prices[i-1]] + pages[i-1];
            }
            int not_taken = dp[i-1][j];
            dp[i][j] = max(taken , not_taken);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}