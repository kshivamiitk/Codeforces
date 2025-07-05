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
    int n , k , x ; cin>> n >> k >> x;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    sort(all(arr));
    int count = 0;
    vpi groups;
    int start = arr[0];
    int end = arr[0];
    f(i , 1 , n){
        if(arr[i] - end <= x ){
            end = arr[i];
        }
        else{
            groups.pb(mp(start , end));
            start = arr[i];
            end = arr[i];
        }
    }
    groups.pb(mp(start , end));
    // for the groups created find the differences between the 
    // group[i+1].start - group[i].end;
    vi differences;
    rep(i , groups.size() - 1){
        int f = groups[i].ss;
        int s = groups[i + 1].ff;
        differences.pb(s - f);
       // cout << differences[i] << " ";
    }
    //cout << endl;
    sort(all(differences));
    int ans = groups.size();
    if(groups.size() == 1){
        cout << 1 << endl;
        return ;
    }
    rep(i , differences.size()){
        // this is going to 
        ///cout << differences[i];
        k -= (differences[i] - 1)/x;
        if(k >= 0) ans--;
        else break;
    }
    cout << ans << endl;
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