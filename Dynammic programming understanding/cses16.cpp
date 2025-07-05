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
struct task{
    int start;
    int end;
    int pay;
};
bool cmp(task &a, task &b){
    if(a.end == b.end) return a.start < b.start;
    return a.end< b.end;
}
signed main()
{
    int n ; 
    cin>>n;
    
    vector<task>projects(n);
    //define dp[i] to be the maxm profit one can acquire till day i
    vector<int>dp(n);
    vi max_price(n);//stores the maxm price if i_th project is the last project
    for(int i = 0 ; i < n ; i++){
        cin>>projects[i].start>>projects[i].end>>projects[i].pay;
    }
    sort(all(projects), cmp);
    dp[0] = projects[0].pay;
    
    for(int i = 1 ; i < n ; i++){
        int low = 0 , high = i-1, idx = -1;
        while(low <= high){
            // move until the top is found
            int mid = (low + high)/2;
            if(projects[mid].end < projects[i].start){
                idx = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }

            dp[i] = projects[i].pay;
            if(idx != -1){
                dp[i] += dp[idx];
            }
            dp[i] = max(dp[i-1] , dp[i]);
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}