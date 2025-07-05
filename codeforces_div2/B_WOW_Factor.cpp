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
    string s; 
    cin >> s;
    int n = s.size();
    
    vector<int> temp;
    char last = s[0];
    int count = 1;
    for (int i = 1; i < n; i++){
        if(s[i] == last){
            count++;
        } else {
            if(last == 'v'){

                temp.pb(max(0LL, count - 1));
            } else {

                temp.pb(count);
            }
            last = s[i];
            count = 1;
        }
    }
    // push the last segment
    if(last == 'v'){
        temp.pb(max(0LL, count - 1));
    } else {
        temp.pb(count);
    }
    

    bool vFirst = (s[0] == 'v');
    
    int totalW = 0;
    int segSize = sz(temp);

    for (int i = 0; i < segSize; i++){
        if((vFirst && i % 2 == 0) || (!vFirst && i % 2 == 1)){
            totalW += temp[i];
        }
    }
    

    ll ans = 0;
    int runningW = 0;
    for (int i = 0; i < segSize; i++){

        if((vFirst && i % 2 == 1) || (!vFirst && i % 2 == 0)){
            int rightW = totalW - runningW; // w's remaining on the right side.
            ans += temp[i] * runningW * rightW;
        } else {

            runningW += temp[i];
        }
    }
    
    cout << ans << "\n";
}

signed main(){
    fast;
    int tc = 1;
    // If multiple test cases, uncomment the next line:
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
