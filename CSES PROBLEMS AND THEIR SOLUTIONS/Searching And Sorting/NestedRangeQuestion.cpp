#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,n) for(int i = 0; i < n; i++)

struct Interval {
    int ff;
    int ss;
    int index;
};

// Comparator function for sorting
bool cmp(const Interval &a, const Interval &b) {
    if (a.ff == b.ff) return a.ss > b.ss; // Sort by starting point, then by end point descending if start points are equal
    return a.ff < b.ff;
}

signed main() {
    fast;
    int n;
    cin >> n;
    vector<Interval> arr(n);
    rep(i, n) {
        cin >> arr[i].ff >> arr[i].ss;
        arr[i].index = i;
    }

    // Sort the intervals based on start point, and end point in descending order if start points are equal
    sort(arr.begin(), arr.end(), cmp);

    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    // Checking whether it contains anything or not
    int minEnd = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i].ss >= minEnd) {
            contains[arr[i].index] = 1;
        }
        minEnd = min(minEnd, arr[i].ss);
    }

    // Checking whether it is contained in some other or not
    int maxEnd = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].ss <= maxEnd) {
            contained[arr[i].index] = 1;
        }
        maxEnd = max(maxEnd, arr[i].ss);
    }

    rep(i, n) cout << contains[i] << " ";
    cout << endl;
    rep(i, n) cout << contained[i] << " ";
    cout << endl;

    return 0;
}
