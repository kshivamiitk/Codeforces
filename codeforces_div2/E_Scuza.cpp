#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

#define int long long
#define endl "\n"
#define vi vector<int>
#define vpi vector<pair<int, int> >
#define inf 1e18

// Binary search function to find the sum corresponding to x
int BS(int x, vpi &arr) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].first <= x && (mid + 1 == arr.size() || arr[mid + 1].first > x)) {
            return arr[mid].second;
        } else if (arr[mid].first < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

// Function to solve each test case
void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int limit = arr[0], sum = 0;
    vpi temp;
    temp.push_back(make_pair(0, 0)); // Initial base case for binary search

    for (int i = 0; i < n; i++) {
        if (arr[i] > limit) {
            temp.push_back(make_pair(limit, sum));
            limit = arr[i];
        }
        sum += arr[i];
    }
    temp.push_back(make_pair(limit, sum));
    temp.push_back(make_pair(inf, inf)); // Upper bound for binary search

    while (q--) {
        int x;
        cin >> x;
        cout << BS(x, temp) << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
