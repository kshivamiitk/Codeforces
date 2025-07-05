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
    fast;
    int n ; 
    cin>>n;
    if(n==1) cout<<1<<endl;
    else if(n==2) cout<<"NO SOLUTION"<<endl;
    else if(n==3) cout<<"NO SOLUTION"<<endl;
    else{
        for(int i = 2 ; i <= n ; i+=2) cout<<i<<" ";
        for(int i = 1 ; i <= n ; i+=2) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}