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
    int pow2 = 2;
    int pow5 = 5;
    int count2 = 0 ;
    int count5 = 0 ;
    while(pow2 <= n){
        count2 += n/pow2;
        pow2 *= 2;
    }
    while(pow5 <= n){
        count5 += n/pow5;
        pow5 *= 5;
    }
    cout<<min(count2 , count5)<<endl;
    return 0;
}