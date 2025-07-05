#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<map>
//this question is there solve the inversion count using the concepts of fenwick tree
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define int long long
#define endl "\n"
void update(vector<int>&bit , int i , int inc , int n)
{
    while(i<=n)
    {
        bit[i]+=inc;
        i+=(i&(-i));
    }
}
int query(vector<int>&bit , int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=bit[i];
        i-=(i&(-i));
    }
    return ans;
}
//now for each index in array it will print how many values before it were greater than it
signed main(){
    int n ;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> bit(n+1,0);
    vector<int> b=a;
    sort(b.begin(),b.end());
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[b[i]]=i+1;
    }
    int ans=0;

    for(int i=n-1;i>=0;i--)
    {
        ans+=query(bit,m[a[i]]-1);
        update(bit,m[a[i]],1,n);
    }
    cout<<ans<<endl;
    return 0;

}