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
struct val{
    int a , b, diff;
};
bool cmp(val a , val b){
    return abs(a.a - a.b) < abs(b.a - b.b);
}
void solve(){
    int n , k1 , k2;
    cin >> n >> k1 >> k2;
    vector<val> values(n);
    vi arr;
    vi a(n);
    vi b(n);
    rep(i , n) cin >> a[i];
    rep(i , n) cin >> b[i];
    rep(i , n){
        values[i].a = a[i];
        values[i].b = b[i];
        arr.pb(abs(values[i].a - values[i].b));
        values[i].diff = abs(values[i].a - values[i].b);
    }
    sort(all(values) , cmp);
    int low = 0 , high = *max_element(all(arr));
    // int ans = -1;
    pq<int> heap;
    rep(i , n){
        // cout << values[i].diff << " ";
        heap.push(values[i].diff);
    }
    cout << endl;
    int total = k1 + k2;
    while(total > 0 && !heap.empty()){
        int top = heap.top();
        heap.pop();
        total--;
        if(top > 0) top--;
        else top++;
        //if(top == 0) continue;
        heap.push(top);
    }
    int ans = 0;
    while(!heap.empty()){
        int top = heap.top();
        heap.pop();
        ans += top * top;
    }
    cout << ans << endl;

}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc  = 1;
    while(tc--){
        solve();
    }
    return 0;
}