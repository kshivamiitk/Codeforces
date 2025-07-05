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

signed main() {
    fast;
    int n;
    cin>>n;
    vector<pair<int,int> >arr;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        pair<int,int> p;

        p.ff = a;
        p.ss = 1;
        arr.pb(p);
        p.ff = b;
        p.ss = -1;
        arr.pb(p);

    }

    stable_sort(arr.begin(),arr.end());
    int answer = 0;
    int current = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        current += arr[i].ss;
        answer = max(answer,current);
    }   
    cout<<answer<<endl;

}
