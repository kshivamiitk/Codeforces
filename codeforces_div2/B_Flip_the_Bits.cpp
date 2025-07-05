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
    int n ; cin >> n;
    string s, t;
    cin >> s >> t;
    vi counts(n , 0);
    int count0 = 0 , count1 = 0;
    rep(i , n){
        s[i] == '1' ? count1++ : count0++;
        counts[i] = count1 - count0;
    }
    count0 = 0 , count1 = 0;
    vi countt(n , 0);
    rep(i , n){
        t[i] == '1' ? count1++ : count0++;
        countt[i] = count1 - count0;
        if(countt[i] == 0 && counts[i] != 0){
            cout << "NO" << endl;return ;
        }
        if(counts[i] == 0 && countt[i] != 0){
            cout << "NO" << endl; return ;
        }
    }
    bool status = true;
    for(int i = n-1 ; i >= 0 ; i--){
        if(s[i] != t[i] && status){
            // means there should be flipping at this point
            status = false;
            if(counts[i] != 0 || countt[i] != 0){
                cout << "NO" << endl;
                return ;
            }
        }
        if(s[i] == t[i] && !status){
            // this was the position that was supposed to be flipped
            status = true;
            if(counts[i] != 0 || countt[i] != 0){
                cout << "NO" << endl;
                return ;
            }
        }
    }
    cout << "YES" << endl;
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