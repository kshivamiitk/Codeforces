#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
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
    int n , m , k ;
    cin>>n>>m>>k;
    vector<int>arr(n);
    vector<int>arr1(m);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    for(int i = 0 ; i < m ; i++) cin>>arr1[i];
    sort(arr.begin() , arr.end());
    sort(arr1.begin() , arr1.end());
    stack<int>st;
    stack<int>st2;
    for(int i = n-1 ; i >= 0 ; i--) st.push(arr[i]);
    for(int i = m-1 ; i >= 0 ; i--) st2.push(arr1[i]);
    int count = 0;
    while(st.size() && st2.size()){
        if(st2.top() < st.top() - k) st2.pop();
        else if(st2.top() > st.top() + k) st.pop();
        else{
            st.pop();
            st2.pop();
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}