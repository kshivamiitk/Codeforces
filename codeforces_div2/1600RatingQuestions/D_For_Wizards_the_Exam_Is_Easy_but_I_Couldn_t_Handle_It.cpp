#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
#define int long long 
#define endl "\n"

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        

        
        int best = -LLONG_MAX;
        int best_i = -1, best_j = -1;
        
        for (int i = 0; i < n; i++){
            int count = 0; 
            int count2 = 0;
            for (int j = i; j < n; j++){
                if(j > i && arr[j] == arr[i]) count2++;
                if(j > i && arr[j] < arr[i]){
                    count++;
                }
                int len = j - i + 1 - count2;

                if(len - count > count) continue;
                
                int value = 2 * count - len;
                if(value > best){
                    best = value;
                    best_i = i;
                    best_j = j;
                }
            }
        }
        
        best_i == -1 && best_j == -1 ? best_i = 0 , best_j = 0 : 1;

        cout << best_i + 1 << " " << best_j + 1 << "\n";
    }
    return 0;
}
