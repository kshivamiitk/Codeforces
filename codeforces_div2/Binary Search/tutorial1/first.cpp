#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

typedef long long int ll;
#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define all(x) x.begin(), x.end()

signed main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi arr(n);
        map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        vi candidates;
        for (auto &[val, count] : freq) {
            if (count >= 2) {
                candidates.push_back(val);
            }
        }

        sort(all(candidates));

        if (candidates.size() < 2) {
            cout << "NO" << endl;
            continue;
        }

        int max_area = 0;
        vi result(8, 0);

        for (int i = 0; i < candidates.size() - 1; i++) {
            for (int j = i + 1; j < candidates.size(); j++) {
                int x1 = candidates[i], x2 = candidates[j];
                int width = abs(x2 - x1);

                // Check if any of them have >= 4 occurrences
                bool x1_four = freq[x1] >= 4;
                bool x2_four = freq[x2] >= 4;
                if (x1_four || x2_four) {
                    int side = (x1_four ? x1 : x2);
                    int area = width * side;
                    if (area > max_area) {
                        max_area = area;
                        result = {x1, side, x1, side, x2, side, x2, side};
                    }
                }

                if (freq[x1] >= 2 && freq[x2] >= 2) {
                    int height = min(freq[x1], freq[x2]);
                    int area = width * height;
                    if (area > max_area) {
                        max_area = area;
                        result = {x1, x2, x1, x2, x1, x2, x1, x2};
                    }
                }
            }
        }

        if (max_area > 0) {
            cout << "YES" << endl;
            for (int i = 0; i < 8; i++) {
                cout << result[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
