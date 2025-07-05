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
    int a , b ;
    cin>>a>>b;

    int n = max(a , b);

    vvi dp(n+1 , vi(n+1 , 0));// the problem of minm moves to cut a rectangle into squares

    for(int i = 1 ; i <= n ; i++){
        dp[i][i] = 0;
    }//if the rectangle is already square
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j){
                continue;
            }
            dp[i][j] = INT_MAX;
            for(int k =1 ; k < i ; k++){
                dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i-k][j] + 1);
            }
            for(int k = 1 ; k < j ; k++){
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}   