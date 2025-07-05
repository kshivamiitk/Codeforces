#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define int long long 
#define endl "\n"
#define rep(i,n) for(int i(0);i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define vvi vector<vector<int> >

int32_t main()
{
    fast
    int n;
    cin >> n; // x is unused, consider removing if not needed
    vi arr(n);

    rep(i, n) cin >> arr[i];

    vi psum(n+1, 0);
    vvi lists(n);

    rep(i, n) {
        psum[i+1] = psum[i] + arr[i];
        int mod_value = (psum[i+1] % n + n) % n; // Handle negative modulo
        lists[mod_value].push_back(i);
    }

    int answer = 0;
    rep(i, n) {
        int k = lists[i].size();
        answer += k * (k - 1) / 2;
    }

    cout << answer << endl;
    return 0;
}
