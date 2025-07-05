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
bool possible(int n , vi arr , int k){
    // need to check if I can push the first n of the array or not into the fridge 
    vi temp;
    rep(i , n){
        temp.pb(arr[i]);
    }
    MAP freq;
    rep(i , n) freq[temp[i]]++;
    vi brr;
    for(auto x : freq){
        if(x.ss >= 2){
            k -= x.ff * (x.ss/2);
            x.ss = x.ss % 2;
            if(x.ss)brr.pb(x.ff);
        }else{
            brr.pb(x.ff);
        }
    }
    sort(all(brr));
    reverse(all(brr));
    for(int i = 0 ; i < brr.size() ; i += 2){
        k -= brr[i];
    }
    return k >= 0;

}
void solve(){
    int n , k;
    cin >> n>> k;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    int low = 1 , high = n ;
    int ans = 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(possible(mid , arr , k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
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