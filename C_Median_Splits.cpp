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
#include<iomanip>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define vc vector<char>
#define vb vector<bool>
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

int modexp(int a, int b) {
    int res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> fact, invfact;
void precomp(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[n] = modexp(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}

bool check_prefix_and_middle(vi &arr, int n){
    vi suf(n), minsuf(n);
    suf[n-1] = minsuf[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]+arr[i];
        minsuf[i]=min(minsuf[i+1],suf[i]);
    }
    int s=0;
    for(int i=0;i+2<n;i++){
        s+=arr[i];
        if(s<0)
            continue;
        if(suf[i+1]>=minsuf[i+2])
            return true;
    }
    return false;
}

void solve(){
    int n , k;
    cin >> n >> k;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    rep(i , n) if(arr[i]<=k) arr[i]=1; else arr[i]=-1;

    int a=n, b=-1, s=0;
    rep(i,n){
        s+=arr[i];
        if(s>=0){
            a=i;
            break;
        }
    }
    s=0;
    for(int i=n-1;i>=0;i--){
        s+=arr[i];
        if(s>=0){
            b=i;
            break;
        }
    }
    if(a+1<b){
        cout<<"YES"<<endl;
        return;
    }
    if(check_prefix_and_middle(arr,n)){
        cout<<"YES"<<endl;
        return;
    }
    reverse(all(arr));
    if(check_prefix_and_middle(arr,n)){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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
