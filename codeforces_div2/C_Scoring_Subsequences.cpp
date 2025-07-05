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
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
int fact(int n){

}
void solve(){
    int n; cin >> n;
    pqv heap;
    int product = 0;
    vi arr(n);
    rep(i , n){
        cin >> arr[i];
        
    }
    int start = 0 , end = 0;
    cout << 1 << " ";
    product = arr[0];
    f(i , 1, n){
        //check if adding the current one is going to make the product more
        // now if the temp comes out to be less than the current one, we update the start until 
            // if((product * arr[i]/ (end - start + 2)) >= product){
            //     product = product * arr[i]/(end - start + 2);
            //     end++;
            //     cout << end - start + 1 << " ";
                
            //     continue;
            // }
            end++;
            product = (product * arr[i]) / (end - start + 2);
            
            while(start <= end && arr[start] < end - start + 1){
                product = (product/arr[start]) * (end - start + 1);
                start++;
            }
            // if((product * arr[i]/ (end - start + 2)) >= product){
            //     product = product * arr[i]/(end - start + 2);
            //     end++;
            //     cout << end - start + 1 << " ";
                
            //     continue;
            // }
            if(start > end) start = end;
            cout << end - start + 1 << " " ;

        
    }
    cout << endl;
}
signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}