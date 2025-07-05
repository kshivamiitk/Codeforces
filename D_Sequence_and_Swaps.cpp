#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> index;
    vector<int> v;
    v.push_back(-1);  // Dummy value for no previous value
    v.push_back(x);
    for (int num : a) {
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    for (int i = 0; i < m; i++) {
        index[v[i]] = i;
    }
    int q0 = index[x];
    vector<vector<long long> > dp_prev(m, vector<long long>(m, 1e18));
    dp_prev[0][q0] = 0;  // p=0 represents no previous value
    for (int i = 1; i <= n; i++) {
        vector<vector<long long> > dp_current(m, vector<long long>(m, 1e18));
        for (int p = 0; p < m; p++) {
            for (int q = 0; q < m; q++) {
                if (dp_prev[p][q] < 1e18) {
                    int a_val = a[i - 1];
                    // No swap
                    if (p == 0 || v[p] <= a_val) {
                        int p_prime = index[a_val];
                        dp_current[p_prime][q] = min(dp_current[p_prime][q], dp_prev[p][q]);
                    }
                    // Swap
                    if ((p == 0 || v[p] <= v[q]) && a_val > v[q]) {
                        int p_prime = q;
                        int q_prime = index[a_val];
                        dp_current[p_prime][q_prime] = min(dp_current[p_prime][q_prime], dp_prev[p][q] + 1);
                    }
                }
            }
        }
        dp_prev = dp_current;
    }
    long long min_ops = 1e18;
    for (int p = 0; p < m; p++) {
        for (int q = 0; q < m; q++) {
            min_ops = min(min_ops, dp_prev[p][q]);
        }
    }
    if (min_ops < 1e18) {
        cout << min_ops << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        solve();
    }
    return 0;
}