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
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define int unsigned long 
#define endl "\n"
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
#define mod 1000000007
#define mod1 1000000009
#define mod2 998244353
#define mod3 1000000007
#define mod4 1000000009
#define mod5 1000000021
signed main() {
    int l, b, n;
    cin >> l >> b >> n;

    // Binary search for the minimum square size
    int low = 0;  // Start with the larger dimension
    int high = 1e9;  // Set an upper bound for binary search
    int answer = high;  // We will search for the minimum valid answer
    int mid;
    while (low + 1 < high) {
         mid = (low + high) / 2;
        
        // Check if mid can fit at least 'n' rectangles of size l x b
        if ((mid / l) * (mid / b) >= n) {
            
            high = mid;  // Try to find a smaller square
        } else {
            low = mid;  // mid is too small, try larger
        }
    }
    (low/l) * (low/b) >= n ? answer = low : answer = high;
    cout << answer << endl;
    return 0;
}