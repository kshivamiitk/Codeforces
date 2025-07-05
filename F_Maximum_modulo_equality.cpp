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
typedef long long ll;
#define mod 1000000007
#define int long long
#define endl "\n"
#define rep(i,n) for(int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void buildTree(vi &tree, const vi &diff, int n) {
    int m = diff.size();
    for (int i = 0; i < m; i++) {
        tree[n + i] = diff[i];
    }
    for (int i = m; i < n; i++) {
        tree[n + i] = 0;
    }
    for (int i = n - 1; i > 0; i--) {
        tree[i] = gcd(tree[2 * i], tree[2 * i + 1]);
    }
}

int queryTree(const vi &tree, int n, int l, int r) {
    int result = 0;
    l += n; r += n;
    while(l < r) {
        if(l & 1) {
            result = gcd(result, tree[l]);
            l++;
        }
        if(r & 1) {
            r--;
            result = gcd(result, tree[r]);
        }
        l /= 2;
        r /= 2;
    }
    return result;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    rep(i, n) {
        cin >> arr[i];
    }
    
    vi diff;
    for (int i = 0; i < n - 1; i++) {
        diff.pb(abs(arr[i] - arr[i + 1]));
    }
    
    if(diff.size() == 0) {
        while(q--){
            int l, r; 
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }
    
    int size = 1;
    while(size < (int)diff.size()) size *= 2;
    
    vi tree(2 * size, 0);
    buildTree(tree, diff, size);
    
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(l == r) {
            cout << 0 << " ";
            continue;
        }
        int res = queryTree(tree, size, l, r);
        cout << (res == 0 ? 0 : res) << " ";
    }
    cout << endl;
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
