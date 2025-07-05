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
const bool cmp(pair<int,int>&a , pair<int,int>&b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
signed main()
{
    int n ; cin>>n;
    vector<pair<int,int> >arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    // I sorted the movies in terms of the movie that is going to end fastest
    sort(arr.begin() , arr.end() , cmp);
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        count++;
        i++;
        int end = arr[i-1].second;
        while(i < n && arr[i].first < end ) i++;
        if(i==n) break;
        i--;
    }
    cout<<count<<endl;
    
    return 0;
}