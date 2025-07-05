#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <cstdint>
using namespace std;

static const int MOD = 998244353;

// Compute (a * b) mod MOD safely using 64-bit intermediate.
long long mulMod(long long a, long long b) {
    a %= MOD;
    b %= MOD;
    return (a * b) % MOD;
}

/*
 * Computes the prefix-function (also known as the failure function in KMP)
 * for an integer array "col". prefix[i] = the length of the longest proper prefix
 * of col[0..i] which is also a suffix of col[0..i].  O(L) time.
 */
vector<int> computePrefixFunction(const vector<int> &col) {
    int L = (int)col.size();
    vector<int> prefix(L, 0);
    int j = 0;
    for (int i = 1; i < L; i++) {
        while (j > 0 && col[i] != col[j]) {
            j = prefix[j - 1];
        }
        if (col[i] == col[j]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

/*
 * Returns the minimal period of the circular array "col".
 * If col has length L, and its prefix-function at the last position is pVal,
 * then a candidate period is L - pVal. If L % (L - pVal) == 0, that is the
 * minimal period. Otherwise, the minimal period is L (no smaller repetition).
 */
int getMinimalPeriod(const vector<int> &col) {
    int L = (int)col.size();
    vector<int> prefix = computePrefixFunction(col);
    int pVal = prefix[L - 1];
    int candidate = L - pVal;
    if (L % candidate == 0) {
        return candidate;
    } else {
        return L;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> p(n), c(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            // Convert to 0-based for easier cycle traversal
            p[i]--;
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }

        // Find cycles of p
        vector<bool> visited(n, false);
        long long answer = 1LL;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                // Collect this cycle
                vector<int> cycleIndices;
                int cur = i;
                while(!visited[cur]){
                    visited[cur] = true;
                    cycleIndices.push_back(cur);
                    cur = p[cur];
                }

                // If cycle length is 1, it contributes factor = 1
                // except we only do something if there's an actual cycle
                // of length > 1. But let's handle all in a uniform way.
                int L = (int)cycleIndices.size();
                if(L > 1) {
                    // Extract color sequence in the order of the cycle
                    vector<int> col(L);
                    for(int k = 0; k < L; k++){
                        col[k] = c[cycleIndices[k]];
                    }

                    // Attempt all possible shifts in that cycle to see if
                    // there's a smaller period, or use prefix function.
                    int d = getMinimalPeriod(col);
                    // We multiply by L/d
                    answer = mulMod(answer, (long long)L / d);
                }
            }
        }

        cout << answer % MOD << "\n";
    }

    return 0;
}
