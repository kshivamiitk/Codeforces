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
    char ch; 
    cin >> ch;
    string s;
    cin >> s;
    
    // Check if the string is already all target characters.
    bool allSame = true;
    rep(i, n) {
        if(s[i] != ch) {
            allSame = false;
            break;
        }
    }
    if(allSame){
        cout << 0 << endl;
        return;
    }
    
    // If the last character is already target,
    // one operation with x = n is enough.
    if(s[n-1] == ch){
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    
    // If the second-to-last character is target,
    // one operation with x = n-1 is enough.
    if(s[n-2] == ch){
        cout << 1 << endl;
        cout << n-1 << endl;
        return;
    }
    
    // Otherwise, answer is always 2 operations:
    // one with x = n and one with x = n-1.
    cout << 2 << endl;
    cout << n << " " << n-1 << endl;
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
