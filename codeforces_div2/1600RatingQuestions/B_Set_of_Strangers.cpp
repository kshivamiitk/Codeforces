#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        

        unordered_map<int,int> cost;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int col = grid[i][j];
                if(cost.find(col) == cost.end())
                    cost[col] = 1; 
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int col = grid[i][j];

                if(j+1 < m && grid[i][j+1] == col)
                    cost[col] = 2;

                if(i+1 < n && grid[i+1][j] == col)
                    cost[col] = 2;
            }
        }
        

        int k = cost.size(); 
        int r = 0; 
        int maxCost = 0;
        int total = 0;
        for (auto &p : cost) {
            total += p.second;
            if(p.second == 2) r++;
            if(p.second > maxCost)
                maxCost = p.second;
        }
        

        if(k == 1){
            cout << 0 << "\n";
            continue;
        }
        

        int ans = total - maxCost;
        cout << ans << "\n";
    }
    return 0;
}
