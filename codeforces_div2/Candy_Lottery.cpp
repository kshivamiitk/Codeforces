#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cfenv>
using namespace std;
#pragma STDC FENV_ACCESS ON

void solve(){
    int n, k;
    cin >> n >> k;
    vector<double> F(k + 1);
    for (int i = 0; i <= k; i++){
        F[i] = pow((double)i / k, n);
    }
    double ans = 0;
    for (int i = 1; i <= k; i++){
        ans += i * (F[i] - F[i - 1]);
    }
    double rounded = rint(ans * 1e6) / 1e6;
    cout << fixed << setprecision(6) << rounded << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
