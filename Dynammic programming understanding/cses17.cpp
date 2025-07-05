#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long int ll;
#define int long long
#define inf LLONG_MAX

signed main() {
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    // Step 1: Precompute weights for all subsets
    vector<int> weights(1 << n, 0);
    for (int X = 0; X < (1 << n); X++) {
        for (int i = 0; i < n; i++) {
            if (X & (1 << i)) { // Check if the i-th bit is set in X
                weights[X] += w[i];
            }
        }
    }

    // Step 2: Initialize dp array
    vector<int> dp(1 << n, inf);
    dp[0] = 0; // Base case: empty set requires 0 subsets

    // Step 3: Compute dp values
    for (int X = 0; X < (1 << n); X++) {
        for (int x = X; x > 0; x = (x - 1) & X) { // Iterate over all subsets of X
            if (weights[x] <= W) { // If subset weight is within limit
                dp[X] = min(dp[X], dp[X ^ x] + 1);
            }
        }
    }

    // Step 4: Output the result for the full set
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}
