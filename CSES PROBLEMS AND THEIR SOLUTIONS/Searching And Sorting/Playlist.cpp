#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#include<map>
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
    int n ;
    cin>>n;
    vector<int>arr(n);
    rep(i , n) cin>>arr[i];
    
    int answer = 0;

    int i = 0 ; 
    int j = 0;
    map<int,int>mp;
    while(i < n && j < n){
        if(mp[arr[j]]==0){
            mp[arr[j]]++;
            j++;
            answer = max(answer , j-i);
        }
        else{
            mp[arr[i]]--;
            i++;
        }
    }
    cout<<answer<<endl;
    return 0;
}