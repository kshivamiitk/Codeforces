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
struct PairHash {
    size_t operator()(const pair<long long, long long>& p) const {
        auto h1 = std::hash<long long>{}(p.first);
        auto h2 = std::hash<long long>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15LL + (h1 << 6) + (h1 >> 2));
    }
};



signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
    int x, y; cin >> x >> y;
    vi arr(n);
    rep(i, n) cin >> arr[i];

    int ans = 0;
    unordered_map<pi, int, PairHash> freq;

    rep(i, n) {
        int f1 = arr[i] % x;
        int s1 = arr[i] % y;

        pi temp;
        temp.ff = (x - f1) % x; // Ensure non-negative
        temp.ss = s1;

        if (freq.find(temp) != freq.end()) {
            ans += freq[temp];
        }
        freq[{f1, s1}]++;
    }
    cout << ans << endl;
    }
    return 0;
}