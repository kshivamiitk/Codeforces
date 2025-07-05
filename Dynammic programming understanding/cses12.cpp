#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1; // Base case: sum 0 is achievable with 0 coins.

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= arr[i-1]) {
                dp[i][j] |= dp[i-1][j - arr[i-1]];
            }
        }
    }

    set<int> ans;
    for (int j = 1; j <= sum; j++) { // Start from 1 to exclude 0.
        if (dp[n][j]) {
            ans.insert(j);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
