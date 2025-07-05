#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
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
    fast;
    int q ;
    cin>>q;
    while(q--){
        unsigned long long k;
        cin>>k;
        int n = 1;
        unsigned long long range_size = 9;
        
        // Find the number of digits in the number
        while(k > range_size * n) {
            k -= range_size * n;
            range_size *= 10;
            n++;
        }

        // Determine the actual number containing the k-th digit
        unsigned long long num = range_size / 9 + (k - 1) / n;
        unsigned long long pos = (k - 1) % n;
        
        cout << to_string(num)[pos] << endl;
    }

    return 0;
}
