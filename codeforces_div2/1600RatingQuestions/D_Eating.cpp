#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <cstdint>

using namespace std;
typedef long long int ll;
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<int, vector<int>, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define mod 1000000007
#define mod1 1000000009
#define mod2 998244353
#define mod3 1000000007
#define mod4 1000000009
#define mod5 1000000021

static const int BIT = 30;
void mergeIntervals(vpi &intervals) {
    if (intervals.empty()) return;
    sort(all(intervals));
    vpi merged;
    pi cur = intervals[0];
    f(i, 1, sz(intervals)) {
        if (intervals[i].ff <= cur.ss) {
            cur.ss = max(cur.ss, intervals[i].ss);
        } else {
            merged.pb(cur);
            cur = intervals[i];
        }
    }
    merged.pb(cur);
    intervals = merged;
}


vpi recCompute(int pos, bool tight, int cur, int A, int T) {
    vpi ret;
    if (pos < 0) {
        ret.pb({cur, cur + 1});
        return ret;
    }
    if (!tight) {
        int L = cur << (pos + 1);
        int R = (cur + 1) << (pos + 1);
        ret.pb({L, R});
        return ret;
    }
    int bitA = (A >> pos) & 1;
    int bitT = (T >> pos) & 1;
    rep(xbit, 2) {
        int ybit = xbit ^ bitA;
        if (ybit < bitT) continue;
        int newCur = (cur << 1) | xbit;
        bool newTight = tight && (ybit == bitT);
        if (!newTight) {
            int L = newCur << pos;
            int R = (newCur + 1) << pos;
            ret.pb({L, R});
        } else {
            vpi sub = recCompute(pos - 1, true, newCur, A, T);
            ret.insert(ret.end(), all(sub));
        }
    }
    mergeIntervals(ret);
    return ret;
}

vpi computeG(int A, int T) {
    vpi ans = recCompute(BIT - 1, true, 0, A, T);
    int M = 1 << BIT;
    vpi ret;
    for (auto &pr : ans) {
        int L = max(pr.ff, 0LL);
        int R = min(pr.ss, M);
        if (L < R) ret.pb({L, R});
    }
    mergeIntervals(ret);
    return ret;
}

vpi intersectIntervals(vpi &v1, vpi &v2) {
    vpi res;
    int i = 0, j = 0;
    while (i < sz(v1) && j < sz(v2)) {
        int L = max(v1[i].ff, v2[j].ff);
        int R = min(v1[i].ss, v2[j].ss);
        if (L < R) res.pb({L, R});
        if (v1[i].ss < v2[j].ss) i++;
        else j++;
    }
    return res;
}

bool inIntervals( vpi &intervals, int x) {
    for (auto &pr : intervals) {
        if (x >= pr.ff && x < pr.ss) return true;
    }
    return false;
}

signed main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vi weights(n);
        rep(i, n) cin >> weights[i];


        vi S(n + 1, 0);
        f(i, 1, n + 1) {
            S[i] = weights[n - i];
        }


        vi Q(n + 1, 0);
        Q[0] = 0;
        f(i, 1, n + 1) {
            Q[i] = Q[i - 1] ^ S[i];
        }

        int M = 1 << BIT;
        vector<vpi> Fsets;
        Fsets.pb({{0, M}});

        int maxK = 0;
        f(k, 1, n + 1) {
            vpi cond = computeG(Q[k - 1], S[k]);
            vpi newF = intersectIntervals(Fsets[k - 1], cond);
            if (newF.empty()) break;
            Fsets.pb(newF);
            maxK = k;
        }


        rep(i, q) {
            int x;
            cin >> x;
            int lo = 0, hi = maxK;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (inIntervals(Fsets[mid], x))
                    lo = mid;
                else
                    hi = mid - 1;
            }
            cout << lo << " ";
        }
        cout << endl;
    }
    return 0;
}
