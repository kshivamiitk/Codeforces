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
    vector<int>arr(n);
    vector<int>subarray(n+1 , 0);
    vector<int>mark(n+1 , 0);
    mark[1] = 1;
    for(int i = 0 ; i < n ; i++) {cin>>arr[i]; subarray[arr[i]] = i;}
    for(int i = 1 ; i < n ; i++){
        if(subarray[i+1] > subarray[i]) mark[i+1] = mark[i];
        else mark[i+1] = mark[i] + 1;
    }
    cout<<mark[n]<<endl;
    return 0;
}