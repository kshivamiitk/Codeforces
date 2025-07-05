#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define int long long 
#define endl "\n"
#define ff  first
#define ss second
#define rep(i,n) for(int i = 0; i < n; i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define vpi vector<pair<int,int> >

bool possible(int mid, const vpi &arr) {
    int n = arr.size();
    // Initially, we are at position 0, so reachable range is [0,0]
    int start = 0, end = 0;
    rep(i, n) {
        int l = arr[i].ff, r = arr[i].ss;
        // From the previous interval [start, end], we can move to [start - mid, end + mid]
        // and we must also lie in the current segment [l, r]
        int newStart = max(l, start - mid);
        int newEnd = min(r, end + mid);
        if(newStart > newEnd) return false;
        start = newStart;
        end = newEnd;
    }
    return true;
}

signed main() {
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vpi arr(n);
        rep(i, n) {
            cin >> arr[i].ff >> arr[i].ss;
        }
        int low = 0, high = 1e9;
        while(low < high) {
            int mid = (low + high) / 2;
            if(possible(mid, arr))
                high = mid;
            else
                low = mid + 1;
        }
        cout << high << endl;
    }
    return 0;
}
