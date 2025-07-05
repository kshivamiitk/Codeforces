#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Base case: Single element
    for (int i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }

    // Fill DP table for subarray lengths from 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] + min(i + 2 <= j ? dp[i + 2][j] : 0,
                                        i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0),
                           arr[j] + min(i <= j - 2 ? dp[i][j - 2] : 0,
                                        i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
