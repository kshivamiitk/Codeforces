#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define int long long 
#define endl "\n"
#define ff  first
#define ss second
#define f(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>

signed main() {
    fast;
    int n;
    cin >> n;
    vector<int> answer;
    
    while (n != 1) {
        answer.pb(n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
    }
    answer.pb(1);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}
