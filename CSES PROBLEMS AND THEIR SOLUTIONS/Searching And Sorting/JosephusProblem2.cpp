#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long int ll;
#define int long long
#define endl "\n"
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        return 0;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    k = k % n;
    vector<int> result;
    int flag = 1;
    int initial_k = k;
    
    while (result.size() < n) {
        if (flag == 0) {
            result.push_back(q.front());
            q.pop();
            k = initial_k % q.size();
            flag = (k == 0) ? 0 : 1;
        } else {
            q.push(q.front());
            q.pop();
            flag = (1 + flag) % (k + 1);
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
