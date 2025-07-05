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
struct seg{
    int l, r , i;
};
bool cmp(seg a , seg b){
    if(a.l == b.l){
        return a.r > b.r ;
    }
    return a.l < b.l ;
}
void solve(){
    int n ;
    cin >> n;
    vi l(n) ;
    vi r(n) ;
    vector<seg> arr(n);
    rep(i , n){
        cin >> l[i] >> r[i];
        arr[i].l = l[i];
        arr[i].r = r[i];
        arr[i].i = i;
    }
    sort(all(arr) , cmp);
    int maxm = LLONG_MIN;
    int maxi = -1;
    rep(i , n){
        if(arr[i].r <= maxm){
            cout << arr[i].i + 1 << " " << maxi + 1 << endl;
            return ;
        }else{
            if(arr[i].r > maxm){
                maxm = arr[i].r;
                maxi = arr[i].i;
            }
        }
    }
    cout << -1 << " " << -1 << endl; 

}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}