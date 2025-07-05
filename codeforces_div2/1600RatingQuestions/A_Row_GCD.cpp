#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  
using namespace std;
#define int long long 
#define endl "\n"
#define rep(i,n) for(int i = 0; i < n; i++)

signed main() {
    int n, m; 
    cin >> n >> m;
    vector<int> arr(n);
    rep(i, n) {
        cin >> arr[i];
    }
    
    if(n == 1) {
        rep(i, m) {
            int x;
            cin >> x;
            cout << arr[0] + x << " ";
        }
        cout << endl;
        return 0;
    }
    

    sort(arr.begin(), arr.end());
    

    int g = 0;
    for (int i = 1; i < n; i++) {
        g = std::gcd(g, arr[i] - arr[0]);
    }
    
    rep(i, m) {
        int x; 
        cin >> x;
        cout << std::gcd(arr[0] + x, g) << " ";
    }
    cout << endl;
    
    return 0;
}
