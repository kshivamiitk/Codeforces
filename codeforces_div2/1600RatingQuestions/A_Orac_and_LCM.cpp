#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> spf(MAX+1, 0);
    for (int i = 2; i <= MAX; i++){
        if (spf[i] == 0) {
            spf[i] = i;
            if ((long long)i * i <= MAX) {
                for (int j = i * i; j <= MAX; j += i)
                    if (spf[j] == 0)
                        spf[j] = i;
            }
        }
    }
    

    const int INF = 1e9;
    vector<int> best(MAX+1, INF), second_best(MAX+1, INF);

    vector<int> countDiv(MAX+1, 0);
    

    for (int i = 0; i < n; i++){
        int x = a[i];

        vector<pair<int,int> > factors;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            pair<int,int> temp;
            temp.first = p , temp.second = cnt;
            factors.push_back(temp);
        }
        // Update the records for the primes that appear in a[i].
        for (auto &pr: factors){
            int p = pr.first;
            int cnt = pr.second;
            countDiv[p]++;
            if (cnt < best[p]) {
                second_best[p] = best[p];
                best[p] = cnt;
            } else if (cnt < second_best[p]) {
                second_best[p] = cnt;
            }
        }
    }
    

    long long ans = 1;
    for (int p = 2; p <= MAX; p++){
        int missing = n - countDiv[p];
        int exp = 0;
        if(missing >= 2){
            exp = 0;
        } else if(missing == 1){
            exp = best[p];
        } else {
            exp = second_best[p];
        }

        for (int i = 0; i < exp; i++){
            ans *= p;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
