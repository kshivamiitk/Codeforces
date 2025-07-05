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
void write(int n , int a , int b , int c){
    if(n==1){
        cout<<a<<" "<<c<<endl;
        return;
    }
    write(n-1 , a , c , b);
    cout<<a<<" "<<c<<endl;
    write(n-1 , b , a , c);

}
signed main()
{
    int n ;
    cin>>n;
    vector<int>answer(n+1 , 0);
    answer[1] = 1;
    for(int i = 2 ; i < n+1 ; i++){
        answer[i] = (2*answer[i-1]+1) % mod;
    }
    cout<<answer[n]<<endl;
    write(n , 1 , 2 , 3);
    return 0;
}