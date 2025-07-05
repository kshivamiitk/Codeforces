#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
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
bool isSafe(int i , int j , vector<string>&board){
    if(board[i][j]=='*') return false;
    for(int k = 0 ; k < 8 ; k++){
        if(board[i][k]=='q') return false;
        if(board[k][j]=='q') return false;
        if(i+k<8 && j+k<8 && board[i+k][j+k]=='q') return false;
        if(i-k>=0 && j-k>=0 && board[i-k][j-k]=='q') return false;
        if(i+k<8 && j-k>=0 && board[i+k][j-k]=='q') return false;
        if(i-k>=0 && j+k<8 && board[i-k][j+k]=='q') return false;
    }

    return true;
    
}

int ways(vector<string>&board , int row){
    if(row==8) return 1;
    int ans = 0;
    for(int i = 0 ; i < 8 ; i++){
        if(isSafe(row,i,board)){
            board[row][i] = 'q';
            ans += ways(board,row+1);
            board[row][i] = '.';
        }
    }
    return ans;

}
signed main()
{
    vector<string>board(8);
    rep(i,8) cin>>board[i];
    cout<<ways(board,0)<<endl;

    return 0;
}