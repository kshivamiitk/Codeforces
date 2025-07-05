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
    int n;
    cin>>n;
    vector<vector<char> > v(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin>>v[i][j];
        }
    }
    vector<vector<int> > dp(n,vector<int>(n,0));
    dp[0][0] = 1;   
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(v[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}