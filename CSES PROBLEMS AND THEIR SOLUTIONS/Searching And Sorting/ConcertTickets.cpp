#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<set>

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
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    vector<int> giving(m);
    multiset<int> priceSet;

    for(int i = 0; i < n; i++) {
        cin >> price[i];
        priceSet.insert(price[i]);
    }
    
    for(int i = 0; i < m; i++) {
        cin >> giving[i];
    }

    for(int i = 0; i < m; i++) {
        auto it = priceSet.upper_bound(giving[i]);
        if (it == priceSet.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            priceSet.erase(it);
        }
    }

    return 0;
}