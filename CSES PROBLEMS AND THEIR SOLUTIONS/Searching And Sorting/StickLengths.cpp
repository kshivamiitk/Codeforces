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
int price(int mid , vector<int>arr){
    int cost = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        cost += abs(arr[i] - mid);
    }
    return cost;
}
signed main()
{
    fast;
    int n;
    cin>>n;
    vector<int>arr(n);
    rep(i , n) cin>>arr[i];
    sort(arr.begin() , arr.end());
    int mid = arr[n/2];
    cout<<price(mid , arr)<<endl;
    

    return 0;
}