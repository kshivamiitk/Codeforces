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
#include <functional>
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

// Custom hash for unsigned __int128 type.
struct Int128Hash {
    size_t operator()(unsigned __int128 x) const {
        // Split x into two 64-bit parts.
        uint64_t low = (uint64_t)x;
        uint64_t high = (uint64_t)(x >> 64);
        // Combine the two parts.
        size_t res = std::hash<uint64_t>()(low);
        res ^= std::hash<uint64_t>()(high) + 0x9e3779b97f4a7c15ULL + (res << 6) + (res >> 2);
        return res;
    }
};

void solve(){
    int n;
    unsigned int p, k; 
    cin >> n >> p >> k;
    
    // Use unordered_map to count frequencies of keys F(a)
    unordered_map<unsigned __int128, int, Int128Hash> freq;
    
    for(int i = 0; i < n; i++){
        unsigned int a;
        cin >> a;
        // Compute F(a) = a^4 XOR (k * a)
        // Use unsigned __int128 for high-precision arithmetic.
        unsigned __int128 A = a;
        unsigned __int128 a4 = A * A * A * A;
        unsigned __int128 ka = k * A;
        unsigned __int128 key = a4 ^ ka;
        freq[key]++;
    }
    
    // Count pairs (i, j) with the same key
    int ans = 0;
    for(auto &it: freq){
        int count = it.second;
        ans += count * (count - 1) / 2;
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
