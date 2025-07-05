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
vpi primes(int n) {
    vpi temp;
    int count = 0;
    
    // Count factors of 2
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0) {
        temp.pb(mp(2, count));
    }
    
    // Check for odd factors up to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0) {
            temp.pb(mp(i, count));
        }
    }
    
    // If n is a prime greater than 2
    if (n > 1) {
        temp.pb(mp(n, 1));
    }
    
    return temp;
}

void solve(){
    int n; cin >> n ;
    vpi temp = primes(n);
    // rep(i , temp.size()){
    //     cout << temp[i].ff << endl;
    // }
    if(temp.size() >= 3){
        cout << "YES" << endl;
        cout << pow(temp[0].ff , temp[0].ss) << " " << pow(temp[1].ff , temp[1].ss) << " ";
        int ans = 1;
        f(i , 2 , temp.size()){
            ans *= pow(temp[i].ff , temp[i].ss);
        }
        cout << ans << endl;
        return;
    }
    if(temp.size() == 2){
        // check if the answer works or not
        int first = temp[0].ff, second = temp[1].ff;
        int third = n/(first * second);
        if(first == third || second == third || third == 1 ){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << first << " " << second << " " << third << endl;
        return ;
    }  
    if(temp.size() == 1){
        int first = temp[0].ff , second = first * first;
        if(n % second !=0){
            cout << "NO" << endl;
            return;
        }
        int third = n / (first * second);
        if(third * first * second != n){
            cout << "NO" << endl;
            return;
        }
        if(first == third || second == third || third == 1 || third == 0){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        cout << first << " " << second << " " << third << endl;
        return ;
    } 
    cout << "NO" << endl;
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