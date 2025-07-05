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
class SegTree {
public:
    int n;
    vector<int> tree, lazy;

    // Constructor to initialize the segment tree with given size
    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    // Merge function for sum queries (modify for other operations)
    int merge(int a, int b) {
        return a + b;
    }

    // Build the segment tree from the input array over the interval [left, right]
    void build(vector<int>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * idx, left, mid);
        build(arr, 2 * idx + 1, mid + 1, right);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    // Push down the lazy propagation value to the children
    void pushDown(int idx, int left, int right) {
        if (lazy[idx] != 0) {
            int mid = (left + right) / 2;
            tree[2 * idx] += lazy[idx] * (mid - left + 1);
            lazy[2 * idx] += lazy[idx];
            tree[2 * idx + 1] += lazy[idx] * (right - mid);
            lazy[2 * idx + 1] += lazy[idx];
            lazy[idx] = 0;
        }
    }

    // Range update: add 'val' to every element in the range [ql, qr]
    void updateRange(int idx, int left, int right, int ql, int qr, int val) {
        if (ql > right || qr < left) return;  // no overlap
        if (ql <= left && right <= qr) {  // complete overlap
            tree[idx] += val * (right - left + 1);
            lazy[idx] += val;
            return;
        }
        pushDown(idx, left, right);
        int mid = (left + right) / 2;
        updateRange(2 * idx, left, mid, ql, qr, val);
        updateRange(2 * idx + 1, mid + 1, right, ql, qr, val);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    }

    // Range query: get the sum of elements in the range [ql, qr]
    int queryRange(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left) return 0;  // no overlap
        if (ql <= left && right <= qr) return tree[idx];  // complete overlap
        pushDown(idx, left, right);
        int mid = (left + right) / 2;
        int leftSum = queryRange(2 * idx, left, mid, ql, qr);
        int rightSum = queryRange(2 * idx + 1, mid + 1, right, ql, qr);
        return merge(leftSum, rightSum);
    }
};

// Example usage:
// vector<int> arr = { ... };
// int n = arr.size();
// SegTree seg(n);
// seg.build(arr, 1, 0, n - 1);
// seg.updateRange(1, 0, n - 1, l, r, val);  // update range [l, r] with value 'val'
// int sum = seg.queryRange(1, 0, n - 1, l, r);  // query sum in range [l, r]
void solve(){
    int n , q;
    cin >> n >> q;
    vi arr(n);
    rep(i , n) cin >> arr[i];
    int sum = accumulate(all(arr) , 0LL);
    vi curr(n , 0);
    int changed = -1;
    int allval = -1;
    int reset = 0;
    while(q--){
        int t;cin >> t;
        if(t == 1){
            int i , x; cin >> i >> x;
            i--;
            if(changed == -1){
                sum -= arr[i];
                sum += x;
                arr[i] = x;
            }else{
                // there are two cases, first the arr[i] is updated after type2 and other is not updated after type2
                // updated after type2
                if(curr[i] < reset){
                    // means not updated since type2
                    curr[i] = reset;
                    // I update it after type2
                    sum -= changed;
                    sum += x;
                    arr[i] = x;
                }else{
                    // means there was change in the val
                    sum -= arr[i];
                    sum += x;
                    arr[i] = x;
                }
            }
        }else{
            // t == 2
            int x;
            cin >> x;
            // means the value of sum is going to changed
            changed = x;
            reset++;
            sum = n * x;
        }
        cout << sum << endl;
    }
    
}
signed main(){
    fast;
    int tc = 1;
    
    while(tc--){
        solve();
    }
    return 0;
}