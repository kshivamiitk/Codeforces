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
    int n ;
    cin >> n ;
    MAP freq;
    vi arr(n);
    rep(i , n){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    vi temp;
    int sum = accumulate(all(arr) , 0LL);
    rep(i , n){
        int curr = sum - arr[i];
        if(curr % 2) continue;
        if(freq.find(curr/2) != freq.end()){
            if(arr[i] == curr/2 && freq[arr[i]] > 1){
                temp.pb(i + 1);
            }else if(arr[i] == curr/2 && freq[arr[i]] == 1){
                continue;
            }else{
                temp.pb(i + 1);
            }
        }
    }
    cout << temp.size() << endl;
    rep(i , temp.size()) cout << temp[i] << " ";
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