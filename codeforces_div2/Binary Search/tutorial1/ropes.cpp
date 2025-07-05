#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include<map>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        // Input array
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort the array (we don't need a priority queue)
        sort(a.begin(), a.end());

        // Using unordered_set to track found elements instead of map
        unordered_set<int> seen;
        int mex = 0;
        map <int , int > last_converted;
        // Process the array
        for (int i = 0; i < n; ++i) {
            int num = a[i];

            if (seen.find(num) == seen.end()) {
                // First occurrence of this number
                seen.insert(num);
            } else {
                // If this number has been found before, increment it using x until unique
                // while (seen.find(num) != seen.end()) {
                //     num += x;
                // }
                //I  need to check what was the value that this number made when it was added +x last time
                //and then add x to it
                if(last_converted.find(num) == last_converted.end()){
                    last_converted[num] = num + x ;
                }else{
                    last_converted[num] += x;
                }
                
            }
        }

        // Calculate the maximum MEX
        while (seen.find(mex) != seen.end()) {
            mex++;
        }

        cout << mex << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
