#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long int ll;
#define int long long 
#define endl "\n"
#define rep(i,n) for(int i = 0; i < n; i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>

signed main(){
    fast;
    int n, k;
    cin >> n >> k;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    
    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0LL);
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        int sum = 0, cnt = 1;
        
        rep(i, n) {
            if (sum + arr[i] > mid) {
                cnt++;
                sum = arr[i];
                if (cnt > k) break;
            } else {
                sum += arr[i];
            }
        }
        
        if (cnt <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
    return 0;
}
