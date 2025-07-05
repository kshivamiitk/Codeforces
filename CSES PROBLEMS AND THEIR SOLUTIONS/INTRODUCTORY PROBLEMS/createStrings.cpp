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
    string s   ; cin >> s ;
    sort(s.begin() , s.end());
    vector<string>answer;
    do{
        answer.pb(s);
    }while(next_permutation(s.begin() , s.end()));
    cout<<answer.size()<<endl;
    for(auto x : answer) cout<<x<<endl;
    
    return 0;
}