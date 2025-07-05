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
signed main()
{
    int tc;
    cin>>tc;
    while(tc--){
        int x , y ;
        cin>>x>>y;
        x--; y--;
        if(x > y){
            if(x % 2 == 0) cout<< x*x + y + 1<<endl;
            else cout<<(x+1)*(x+1) - y<<endl;
        }
        else{
            if(y % 2 == 1) cout<<y*y + x + 1<<endl;
            else cout<<(y+1)*(y+1) - x<<endl;
        }
    }
    return 0;
}