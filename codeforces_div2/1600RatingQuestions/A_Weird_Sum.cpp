#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define int long long 
#define endl "\n"
#define ff first
#define ss second
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define vpi vector<pair<int,int>>
signed main(){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        unordered_map<int, vpi> same;
        rep(i, n){
            rep(j, m){
                int x;
                cin >> x;
                grid[i][j] = x;
                same[x].pb({i, j});
            }
        }
        int cost = 0;
        for(auto &p : same){
            vpi &cells = p.second;
            int s = cells.size();
            for(int i = 0; i < s; i++){
                for(int j = i + 1; j < s; j++){
                    cost += abs(cells[i].ff - cells[j].ff) + abs(cells[i].ss - cells[j].ss);
                }
            }
        }
        cout << cost << endl;
    
    return 0;
}
