#include<iostream>
using namespace std;
#define vvc vector<vector<char> >
#define vvb vector<vector<bool> >
#define vvi vector<vector<int> >
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
void dfs(int x , int y , int n , int m , vvc &grid ,vvb &visited){
    visited[x][y] = true;
    for(int i = 0 ; i < 4 ; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !visited[x1][y1] && grid[x1][y1] == '1'){
            dfs(x1 , y1 , n , m , grid , visited);
        }
    }
}
int findcost(int n , int m , vector<vector<char> >grid){
    vvb visited(n , vector<bool>(m , false));
    vvi mark(n , vector<int>(m , 0));
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                ans += pow(2 , i);
                dfs(i , j , n , m , grid , visited);
            }
        }
    }
    return ans ;
}
int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        vvc grid(n, vector<char>(m));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << findcost(n, m, grid) << "\n";
    }

    return 0;
}
