#include <iostream>
#include <vector>
using namespace std;

#define int long long 
#define endl "\n"
#define rep(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define vpi vector<pair<int, int>>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, k;
        cin >> a >> b >> k;

        vi arr(a, 0);   // count of edges for vertices in set A
        vi brr(b, 0);   // count of edges for vertices in set B
        vpi edges(k);

        // Read the first endpoints
        rep(i, k) {
            cin >> edges[i].first;
        }
        // Read the second endpoints
        rep(i, k) {
            cin >> edges[i].second;
        }
        
        // Convert to 0-index and count frequency
        rep(i, k) {
            edges[i].first--;   // converting to 0-indexed
            edges[i].second--;  // converting to 0-indexed
            arr[edges[i].first]++;
            brr[edges[i].second]++;
        }
        
        int ans = 0;
        // For each edge, add the number of pairs it can form without sharing vertices
        rep(i, k) {
            ans += (k - arr[edges[i].first] - brr[edges[i].second] + 1);
        }
        // Each pair is counted twice, so divide by 2
        cout << ans / 2 << endl;
    }
    
    return 0;
}
