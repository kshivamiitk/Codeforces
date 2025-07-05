#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define int long long 
#define endl "\n"

// Function to count the power of 2 in n
int count2(int n) {
    int cnt = 0;
    while(n && n % 2 == 0) {
        cnt++;
        n /= 2;
    }
    return cnt;
}

// Function to count the power of 5 in n
int count5(int n) {
    int cnt = 0;
    while(n && n % 5 == 0) {
        cnt++;
        n /= 5;
    }
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        

        int base2 = count2(n);
        int base5 = count5(n);
        
        int bestZeros = -1;
        int bestProduct = 0;
        

        for (int i = 0, p2 = 1; p2 <= m; i++){
            for (int j = 0, p5 = 1; p2 * p5 <= m; j++){
                int candidate = p2 * p5;
                int multiplier = candidate * (m / candidate);
                int currZeros = min(base2 + i, base5 + j);
                int currProduct = n * multiplier;
                if (currZeros > bestZeros) {
                    bestZeros = currZeros;
                    bestProduct = currProduct;
                } else if (currZeros == bestZeros) {
                    bestProduct = max(bestProduct, currProduct);
                }
                p5 *= 5;
            }
            p2 *= 2;
        }
        
        cout << bestProduct << endl;
    }
    return 0;
}
