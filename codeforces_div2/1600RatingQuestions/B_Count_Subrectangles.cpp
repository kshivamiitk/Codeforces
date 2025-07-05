#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
using namespace std;

#define int long long 
#define endl "\n"
#define pb push_back
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    // Count contiguous segments of ones in array a.
    multiset<int> segA;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            cnt++;
        else {
            if (cnt > 0)
                segA.insert(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0)  // Account for a segment ending at the last element.
        segA.insert(cnt);

    // Count contiguous segments of ones in array b.
    multiset<int> segB;
    cnt = 0;
    for (int j = 0; j < m; j++) {
        if (b[j] == 1)
            cnt++;
        else {
            if (cnt > 0)
                segB.insert(cnt);
            cnt = 0;
        }
    }
    if (cnt > 0)
        segB.insert(cnt);

    // Get all divisors of k.
    vi divisors;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            if (i * i == k)
                divisors.pb(i);
            else {
                divisors.pb(i);
                divisors.pb(k / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    // For a segment of length L, the number of contiguous subsegments of length d is (L - d + 1).
    // Count for each possible length d (which is a divisor of k) from array a.
    map<int, int> waysA;
    for (auto seg : segA) {
        for (auto d : divisors) {
            if (d <= seg)
                waysA[d] += (seg - d + 1);
            else
                break;  // Since divisors are sorted, no need to check further.
        }
    }

    // Similarly, count for array b.
    map<int, int> waysB;
    for (auto seg : segB) {
        for (auto d : divisors) {
            if (d <= seg)
                waysB[d] += (seg - d + 1);
            else
                break;
        }
    }

    // Combine the counts: for each divisor d, we pair it with k/d.
    int ans = 0;
    for (auto d : divisors) {
        int d2 = k / d;
        ans += waysA[d] * waysB[d2];
    }
    
    cout << ans << endl;
    return 0;
}
