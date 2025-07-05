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
struct node{
    int c, v;
};
bool cmp(node a , node b){
    return a.v < b.v;
}
void solve(){
    int n1, n2 , n3 , n4;
    cin >> n1;
    vi arr1(n1) ;
    rep(i , n1) cin >> arr1[i];
    cin >> n2;
    vi arr2(n2);
    rep(i , n2) cin >> arr2[i];
    cin >> n3;
    vi arr3(n3);
    rep(i , n3) cin >> arr3[i];
    cin >> n4;
    vi arr4(n4);
    rep(i , n4) cin >> arr4[i];
    vector<node>arr(n1 + n2 + n3 + n4);
    rep(i , n1){
        arr[i].c = 1;
        arr[i].v = arr1[i];
    }
    rep(i , n2){
        arr[i + n1].c = 2;
        arr[i + n1].v = arr2[i];
    }
    rep(i , n3){
        arr[i + n1 + n2].c = 3;
        arr[i + n1 + n2].v = arr3[i];
    }
    rep(i , n4){
        arr[i + n1 + n2 + n3].c = 4;
        arr[i + n1 + n2 + n3].v = arr4[i];
    }
    sort(all(arr) , cmp);
    vi freq(5 , 0);
    vi val(4 , ninf);
    int left = 0 ; 
    int ans = inf;
    int count = 0;
    int bestl = -1 , bestr = -1;
    rep(i , n1 + n2 + n3 + n4){
        if(freq[arr[i].c]++ == 0)count++;
        while(count == 4){
            int curr = arr[i].v - arr[left].v;
            if(curr < ans){
                ans = curr;
                bestl = left;
                bestr = i;
            }
            if(--freq[arr[left].c] == 0) count--;
            left++;
        }
    }
    vi answer(5, 0);
    f(i , bestl , bestr + 1){
        int cat = arr[i].c;
        if(answer[cat] == 0) answer[cat] = arr[i].v;
    }
    f(i , 1 , 5) cout << answer[i] << " " ;
    cout << endl;
    
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