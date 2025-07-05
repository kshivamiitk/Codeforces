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

 
signed main(){
    fast
    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> freq(n+1, 0);
        for (int i = 0; i < n; i++){
            freq[a[i]]++;
        }
        int bestLen = 0, bestL = -1, bestR = -1;
        int currL = -1;
        for (int i = 0; i < n; i++){
            if(freq[a[i]] == 1){
                if(currL == -1)
                    currL = i;  
            } else {
               
                if(currL != -1){
                    int len = i - currL;
                    if(len > bestLen){
                        bestLen = len;
                        bestL = currL;
                        bestR = i - 1;
                    }
                    currL = -1; 
                }
            }
        }
        // Check at the end of the array if we were in a valid segment
        if(currL != -1){
            int len = n - currL;
            if(len > bestLen){
                bestLen = len;
                bestL = currL;
                bestR = n - 1;
            }
        }
 

        if(bestLen == 0){
            cout << 0 << "\n";
        } else {
            cout << bestL + 1 << " " << bestR + 1 << "\n";
        }
    }
    return 0;
}
