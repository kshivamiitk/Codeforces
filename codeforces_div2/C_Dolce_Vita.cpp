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
int BS(vi &psum , int x , int &day){
    // find the number of packs that can be purchased
    //if(psum[0] + day > x) return 0;
    int low = 0 , high = sz(psum)-1;
    int ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(psum[mid] + (mid + 1) * day <= x){
            ans = mid + 1;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    int prev = day;
    /// update day keeping the ans same
    
    // suppose the day , day + 1 , day + 2 .... day given is in the answer
    // now I need to 
    day = (x - psum[ans-1])/ans;
    ans = (day - prev + 1) * ans ;
    /// ans should tell you how many shops you can visit with this particular 
    return ans;
}
void solve(){
    int n , x;
    cin >> n >> x;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    sort(all(arr));
    // find the cheapest store
    vi psum(n , 0);
    psum[0] = arr[0];
    f(i , 1 , n) psum[i]=psum[i-1] + arr[i];
    int pack = 0;
    // using binary search I can find the number of packets on day i in logn time
    // I can find the day after which the person is not able to buy the second packet
    int lastday = x - arr[0] + 1;
    // the last day when the person is able to buy something
    int day = 0;
    while(day <= lastday){
        if(psum[0] + day > x) break;
        int shops = BS(psum , x , day);
        pack += shops;
        day++;
    }
    cout << pack << endl;

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