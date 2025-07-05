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
#include<iomanip>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define vc vector<char>
#define vb vector<bool>
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
struct DSU{
    int n ;
    vi parent, size, sum , diff;
    DSU(int m): n(m){
        parent.resize(n + 1);
        iota(all(parent) , 0LL);
        size.resize(n + 1 , 1);
        sum.resize(n + 1 , 0LL);
        diff.resize(n + 1 , 0LL);
    }
    int get(int x){
        if(x != parent[x]){
            int p = parent[x];
            int r = get(p);
            diff[x] += diff[p];
            return parent[x] = r;
        }
        return parent[x];
    }
    void unite(int a , int b){
        a = get(a);
        b = get(b);
        if(a != b){
            if(size[a] > size[b])swap(a , b);
            parent[a] = b;
            size[b] += size[a];
            diff[a] = sum[b] - sum[a];
        }
    }
    int getScore(int a){
        int r = get(a);
        return sum[r] - diff[a];
    }
    void addv(int a , int v){
        int r = get(a);
        sum[r] += v;
    }
};
void solve(){
    int n , q;
    cin >> n >> q;
    DSU dsu(n);
    while(q--){
        string s;
        cin >> s;
        if(s == "join"){
            int a , b;
            cin >> a >> b;
            dsu.unite(a , b);
        }else if(s == "get"){
            int x ; cin >> x;
            cout << dsu.getScore(x) << endl;
        }else{
            int x , y;
            cin >> x >> y;
            dsu.addv(x , y);
        }
    }
}
signed main(){
    fast;
    int tc;
    // cin >> tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}