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
    vector<string>answer;
    if(n == 1) {cout<<"0\n1\n"; return 0;}
    answer.pb("0");
    answer.pb("1");
    for(int i = 2 ; i < (1<<n) ; i = i*2){
        for(int j = i-1 ; j >= 0 ; j--) answer.pb(answer[j]);
        for(int j = 0 ; j < i ; j++) answer[j] = "0" + answer[j];
        for(int j = i ; j < 2*i ; j++) answer[j] = "1" + answer[j];
    }
    for(int i = 0 ; i < (1<<n) ; i++) cout<<answer[i]<<endl;
    return 0;
}