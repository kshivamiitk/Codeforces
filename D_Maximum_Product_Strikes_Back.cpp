#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <iomanip>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define int long long
#define endl "\n"
#define f(i,a,b) for(int i = a; i < b; i++)
#define rep(i,n) for(int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
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
#define eps 1e-9

int modexp(int a, int b){
    int r = 1;
    a %= mod;
    while(b > 0){
        if(b & 1)
            r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

vector<int> fct, ifct;
void precomp(int n){
    fct.resize(n + 1);
    ifct.resize(n + 1);
    fct[0] = 1;
    f(i,1,n+1) fct[i] = (fct[i-1]* i) % mod;
    ifct[n] = modexp(fct[n], mod-2);
    for(int i = n - 1; i >= 0; i--) ifct[i] = (ifct[i+1]*(i+1)) % mod;
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &x : a) cin >> x;
    
    double bestlog = 0.0;
    int bestx = n, besty = 0;
    
    int i = 0;
    const double log2val = log(2.0);
    while(i < n){
        if(a[i] == 0){
            i++;
            continue;
        }
        int segstart = i;
        while(i < n && a[i] != 0) i++;
        int segend = i - 1;
        int seglen = segend - segstart + 1;
 
        int cntneg = 0, firstneg = -1, lastneg = -1;
        f(j,0,seglen){
            if(a[segstart + j] < 0){
                cntneg++;
                if(firstneg == -1)
                    firstneg = j;
                lastneg = j;
            }
        }
 
        vector<double> pref(seglen+1, 0.0);
        f(j,0,seglen){
            double add = (abs(a[segstart+j]) == 2 ? log2val : 0.0);
            pref[j+1] = pref[j] + add;
        }
 
        if(cntneg % 2 == 0){
            double candlog = pref[seglen];
            if(candlog > bestlog + 1e-12){
                bestlog = candlog;
                bestx = segstart;
                besty = n - segend - 1;
            }
        }
        else{
            if(firstneg != seglen - 1){
                double candlog = pref[seglen] - pref[firstneg+1];
                if(candlog > bestlog + 1e-12){
                    bestlog = candlog;
                    int l = segstart + firstneg + 1;
                    int r = segend;
                    bestx = l;
                    besty = n - r - 1;
                }
            }
            if(lastneg != 0){
                double candlog = pref[lastneg];
                if(candlog > bestlog + 1e-12){
                    bestlog = candlog;
                    int l = segstart;
                    int r = segstart + lastneg - 1;
                    bestx = l;
                    besty = n - r - 1;
                }
            }
        }
    }
    cout << bestx << " " << besty << "\n";
}

signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
