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

bool canDo(const vi &t, const vi &z, const vi &y, ll T, ll m) {
    ll total = 0;
    int n = t.size();
    rep(i, n) {
        ll cycle = t[i] * z[i] + y[i];
        ll full = T / cycle;
        ll rem  = T % cycle;
        ll cnt  = full * z[i] + min(z[i], rem / t[i]);
        total += cnt;
        if (total >= m) return true;
    }
    return total >= m;
}

void solve(){
    ll m;
    int n;
    cin >> m >> n;
    vi t(n), z(n), y(n);
    rep(i, n) cin >> t[i] >> z[i] >> y[i];
    if (m == 0) {
        cout << 0 << "\n";
        rep(i, n) {
            cout << 0 << (i+1<n ? ' ' : '\n');
        }
        return;
    }
    ll low = 0, high = 1;
    while (!canDo(t, z, y, high, m)) {
        high *= 2;
    }
    ll ans = high;
    while (low <= high) {
        ll mid = (low + high) >> 1;
        if (canDo(t, z, y, mid, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    vi cnt(n);
    ll total = 0;
    rep(i, n) {
        ll cycle = t[i] * z[i] + y[i];
        ll full = ans / cycle;
        ll rem  = ans % cycle;
        ll c    = full * z[i] + min(z[i], rem / t[i]);
        cnt[i] = c;
        total += c;
    }
    ll extra = total - m;
    struct A { int idx; ll last; };
    vector<A> order;
    order.reserve(n);
    rep(i, n) {
        ll cycle = t[i] * z[i] + y[i];
        ll full = ans / cycle;
        ll rem  = ans % cycle;
        ll used = min(z[i], rem / t[i]);
        ll lastTime = full * cycle + used * t[i];
        order.push_back({i, lastTime});
    }
    sort(order.begin(), order.end(), [&](const A &a, const A &b) {
        return a.last > b.last;
    });
    for (auto &a : order) {
        if (extra == 0) break;
        ll take = min(extra, 1LL);
        cnt[a.idx] -= take;
        extra -= take;
    }
    cout << ans << "\n";
    rep(i, n) {
        cout << cnt[i] << (i+1<n ? ' ' : '\n');
    }
}

signed main(){
    fast;
    int tc;
    tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
