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

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
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
    // Not used in main.
}

signed main(){
    fast;
    int arr[] = {4, 8, 15, 16, 23, 42};

    vector<int> temp;
    cout << "? " << 1 << " " << 2 << endl;
    fflush(stdout);
    {
        int prod;
        cin >> prod;
        temp.pb(prod);
    }
    cout << "? " << 2 << " " << 3 << endl;
    fflush(stdout);
    {
        int prod;
        cin >> prod;
        temp.pb(prod);
    }

    cout << "? " << 4 << " " << 5 << endl;
    fflush(stdout);
    {
        int prod;
        cin >> prod;
        temp.pb(prod);
    }
    cout << "? " << 5 << " " << 6 << endl;
    fflush(stdout);
    {
        int prod;
        cin >> prod;
        temp.pb(prod);
    }

    map<int, pi> freq;
    rep(i,6){
        f(j, i+1,6){
            freq[arr[i] * arr[j]] = mp(arr[i], arr[j]);
        }
    }
    
    pi fp = freq[temp[0]]; 
    pi sp = freq[temp[1]]; 

    map<int, int> count;
    count[fp.ff]++; count[fp.ss]++;
    count[sp.ff]++; count[sp.ss]++;
    int a2 = -1;
    for(auto p : count){
        if(p.second == 2){
            a2 = p.first;
            break;
        }
    }
    int a1, a3;
    if(fp.ff == a2)
        a1 = fp.ss;
    else
        a1 = fp.ff;

    if(sp.ff == a2)
        a3 = sp.ss;
    else
        a3 = sp.ff;
    fp = freq[temp[2]]; 
    sp = freq[temp[3]]; 
    count.clear();
    count[fp.ff]++; count[fp.ss]++;
    count[sp.ff]++; count[sp.ss]++;
    int a5 = -1;
    for(auto p : count){
        if(p.second == 2){
            a5 = p.first;
            break;
        }
    }
    int a4, a6;
    if(fp.ff == a5)
        a4 = fp.ss;
    else
        a4 = fp.ff;
    if(sp.ff == a5)
        a6 = sp.ss;
    else
        a6 = sp.ff;
    cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;
    fflush(stdout);
    return 0;
}
