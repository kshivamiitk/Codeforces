#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define int long long 
#define endl "\n"
#define ff  first
#define ss second
#define f(i,a,b) for(int i(a);i<b;i++)
#define rep(i,n) for(int i(0);i<n;i++)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>

signed main()
{
    int n, t;
    cin >> n >> t;
    vi arr(n);
    rep(i, n) cin >> arr[i];
    int l = 1, r = 1e18, ans = r;
    
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int sum = 0;
        rep(i, n)
        {
            sum += min(mid / arr[i], (long long)1e18);
            if (sum >= t) break;  // To prevent unnecessary computations
        }
        
        if (sum >= t)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}
