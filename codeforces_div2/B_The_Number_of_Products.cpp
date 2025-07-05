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

void solve(){
    int n; cin >> n ;
    vi arr(n);
    rep(i , n ) cin >> arr[i];
    // check the last positive
    vi pos(n + 1 , 0);
    vi neg(n + 1 , 0);
    // p[i] tells you number of positives which end at arr[i-1]
    // n[i] tells you number of negatives which end at arr[i-1];
    arr[0] < 0 ? neg[1] = 1 : pos[1] = 1 ;

    f(i , 1 , n){
        if(arr[i] < 0){
            neg[i + 1] = pos[i] + 1;
            pos[i+1] = neg[i];
        }else{
            neg[i + 1] = neg[i];
            pos[i+1] = pos[i] + 1;
        }
    }
    // rep(i , n + 1) cout << pos[i] << " ";
    // cout << endl; 
    cout << accumulate(all(neg) , 0LL) << " " << accumulate(all(pos) , 0LL) << endl;
}
signed main(){
    fast;
    int tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}