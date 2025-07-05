#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long int ll;
#define int long long 
#define endl "\n"
#define rep(i,n) for(int i(0);i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>

int32_t main()
{
    fast
    int n, k;
    cin >> n >> k;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    
    int l = 0, r = 0;
    map<int, int> mp;
    int count = 0;
    int distinct = 0;

    while (l < n) {
        while (r < n && distinct < k) {
            if (mp[arr[r]] == 0) {
                distinct++;
            }
            mp[arr[r]]++;
            r++;
        }

        if (distinct < k) break;

        count += n - r + 1;

        mp[arr[l]]--;
        if (mp[arr[l]] == 0) {
            distinct--;
        }
        l++;
    }

    cout << count << endl;
    return 0;
}
