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
    int n , x;
    cin>>n>>x;
    vector<pair<int,int> >arr(n);
    rep(i , n) cin>>arr[i].first , arr[i].second = i+1;
    sort(arr.begin() , arr.end());
    int i = 0 ; int j = n-1;
    while(i < n && j>=0 && i<j && arr[i].first + arr[j].first != x){
        if( i < j && arr[i].first + arr[j].first < x) i++;
        else j--;
    }
    if(i >= j || i==n || j==0 || arr[i].first + arr[j].first != x) {cout<<"IMPOSSIBLE"<<endl ; return 0;}
    if(arr[i].second < arr[j].second) cout<<arr[i].second<<" "<<arr[j].second<<endl;
    else cout<<arr[j].second<<" "<<arr[i].second<<endl;
    return 0;
}