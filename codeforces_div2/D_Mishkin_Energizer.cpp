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
#define f(i,a,b) for(int i=a; i<b; i++)
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
char different(char c1, char c2){
    if(c1=='T' && c2=='I') return 'L';
    if(c1=='I' && c2=='T') return 'L';
    if(c1=='T' && c2=='L') return 'I';
    if(c1=='L' && c2=='T') return 'I';
    if(c1=='I' && c2=='L') return 'T';
    if(c1=='L' && c2=='I') return 'T';
    return ' ';
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> freq;
    rep(i,n) freq[s[i]]++;
    if(freq['L']==freq['I'] && freq['I']==freq['T']){
        cout << 0 << endl;
        return;
    }
    int t = max(freq['L'], max(freq['I'], freq['T']));
    bool solved = false;
    vi ans;
    for(int i = t; i <= n; i++){
        int m = 3*i - n;
        if(m > 2*n) break;
        map<char,int> need;
        need['L'] = i - freq['L'];
        need['I'] = i - freq['I'];
        need['T'] = i - freq['T'];
        string cur = s;
        vi ops;
        bool progress = true;
        while(ops.size() < m && progress){
            progress = false;
            for(int i = 0; i < cur.size()-1; i++){
                if(cur[i] == cur[i+1]) continue;
                char x = different(cur[i], cur[i+1]);
                if(need[x] > 0){
                    ops.pb(i+1);
                    cur.insert(cur.begin()+i+1, x);
                    need[x]--;
                    progress = true;
                    break;
                }
            }
        }
        if(ops.size() == m && need['L']==0 && need['I']==0 && need['T']==0){
            solved = true;
            ans = ops;
            break;
        }
    }
    if(!solved) cout << -1 << endl;
    else{
        cout << ans.size() << endl;
        for(auto pos: ans) cout << pos << endl;
    }
}
signed main(){
    fast;
    int tc; cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}
