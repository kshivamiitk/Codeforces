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
    int n; 
    cin >> n;
    char c1, c2;
    int n1, n2;
    
    // Process the first gate pair separately.
    cin >> c1 >> n1 >> c2 >> n2;
    int l0 = 1, r0 = 1; // locked counts: cannot be reallocated
    int l1, r1;       // bonus counts: can be allocated arbitrarily
    
    // For an addition gate, bonus is just the given number.
    // For a multiplication gate, bonus is (a - 1) times the current lane count.
    if(c1 == '+') 
        l1 = n1;
    else 
        l1 = (n1 - 1) * (l0);  // current left count is l0 (which is 1)
    
    if(c2 == '+') 
        r1 = n2;
    else 
        r1 = (n2 - 1) * (r0);  // current right count is r0 (which is 1)
    
    n--; // already processed one pair
    
    while(n--){
        cin >> c1 >> n1 >> c2 >> n2;
        // Lock in the previous bonus before processing new gates.
        l0 += l1;
        r0 += r1;
        
        if(c1 == '+' && c2 == '+'){
            // Both addition: simply assign new bonus.
            l1 = n1;
            r1 = n2;
        }
        else if(c1 == '+' && c2 == 'x'){
            // Left addition, right multiplication.
            l1 = n1;                     // bonus from left addition.
            r1 = (n2 - 1) * (r0);          // bonus from right multiplication uses current right locked count.
        }
        else if(c1 == 'x' && c2 == '+'){
            // Left multiplication, right addition.
            l1 = (n1 - 1) * (l0);          // bonus from left multiplication uses current left locked count.
            r1 = n2;                     // bonus from right addition.
        } else {
            // Both multiplication: we can allocate the entire bonus arbitrarily.
            // Here, we compare (n1 - 1) and (n2 - 1) and assign all bonus to the lane with the larger multiplier.
            if(n1 - 1 >= n2 - 1){
                l1 = (n1 - 1) * (l0 + r0);
                r1 = 0;
            } else {
                r1 = (n2 - 1) * (l0 + r0);
                l1 = 0;
            }
        }
    }
    cout << (l0 + l1 + r0 + r1) << endl;
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
