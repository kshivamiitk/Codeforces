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

    
    int sum = (n * (n + 1)) / 2;
    if(sum%2==1){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
        vi a, b;
        int sum1 = 0, sum2 = 0;
        for(int i = n; i >= 1; i--){
            if(sum1 <= sum2){
                a.pb(i);
                sum1 += i;
            }
            else{
                b.pb(i);
                sum2 += i;
            }
        }
        cout<<a.size()<<endl;
        for(int i = 0; i < a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<b.size()<<endl;
        for(int i = 0; i < b.size(); i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }

    

    

    return 0;
}