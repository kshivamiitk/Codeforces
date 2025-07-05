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
#define mod 1000000007
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
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctz(x)
#define inf 1000000000
#define ninf -1000000000
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

void solve(){
    int x, y;
    cin >> x >> y;
    
    // Function to convert a number to its binary string (without leading zeros)
    auto toBinary = [&](int a) -> string {
         if(a == 0) return "0";
         string s = "";
         while(a > 0) {
              s.push_back((char)('0' + (a % 2)));
              a /= 2;
         }
         reverse(s.begin(), s.end());
         return s;
    };
    
    string xs = toBinary(x);
    string ys = toBinary(y);
    
    // Find longest common prefix (LCP)
    int lcp = 0;
    int l = min(xs.size(), ys.size());
    while(lcp < l && xs[lcp] == ys[lcp]) lcp++;
    
    int d1 = xs.size() - lcp; // extra bits to remove from x
    int d2 = ys.size() - lcp; // extr
