#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define int ll

// Returns the smallest integer that is not allowed (i.e. uses a bit not in x)
int get_m(int x) {
    int m = 0;
    while (true) {
        // if m uses any bit that x does not, it is not allowed
        if (m & (~x))
            break;
        m++;
    }
    return m;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        
        // When n == 1, there is no freedom.
        if(n == 1){
            cout << x << "\n";
            continue;
        }
        
        int m = get_m(x); // the contiguous allowed block is [0, m)
        // Compute OR for a given range [L, R]
        auto compute_or = [&](int L, int R) -> int {
            int res = 0;
            for (int i = L; i < R; i++) {
                res |= i;
            }
            return res;
        };
        
        vector<int> ans;
        // Case 1: n is small so that we cannot include more than n allowed numbers.
        if(n <= m) {
            // Candidate is [0, n)
            int r = compute_or(0, n);
            if(r == x){
                for (int i = 0; i < n; i++){
                    ans.push_back(i);
                }
            } else {
                // Replace the largest element with x to fix the OR.
                // (n must be at least 2 here.)
                for (int i = 0; i < n - 1; i++){
                    ans.push_back(i);
                }
                ans.push_back(x);
            }
        } else { 
            // Case 2: n > m so we can include the entire block [0, m)
            int r = compute_or(0, m);
            if(r == x) {
                // Use the block [0, m) and fill remaining slots with 0.
                for (int i = 0; i < m; i++){
                    ans.push_back(i);
                }
                while(ans.size() < (size_t)n)
                    ans.push_back(0);
            } else {
                // We need an extra allowed number that covers missing bits.
                // Adding x (which is allowed) does the job.
                for (int i = 0; i < m; i++){
                    ans.push_back(i);
                }
                ans.push_back(x);
                while(ans.size() < (size_t)n)
                    ans.push_back(0);
            }
        }
        
        // Output answer
        for(auto a : ans)
            cout << a << " ";
        cout << "\n";
    }
    return 0;
}
