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
    int n ; cin >> n ;
    vector<int>arr(n);
    rep(i , n) cin>>arr[i];
    int answer = LLONG_MAX;
    for(int i = 0 ; i < (1<<n) ; i++){
        int sum1 = 0 , sum2 = 0;
        for(int j = 0 ; j < n ; j++){
            if(i & (1<<j)) sum1 += arr[j];
            else sum2 += arr[j];
        }
        answer = min(answer , abs(sum1 - sum2));
    }
    cout<<answer<<endl;
    return 0;
}