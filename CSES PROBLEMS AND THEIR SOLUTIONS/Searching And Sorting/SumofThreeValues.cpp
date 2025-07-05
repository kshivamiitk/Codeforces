#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<list>
#include<deque>
#include<forward_list>
#include<array>
#include<tuple>
#include<functional>
#include<iterator>
#include<numeric>
#include<utility>
#include<complex>
#include<valarray>
#include<random>
#include<regex>
#include<atomic>
#include<thread>
#include<mutex>
#include<shared_mutex>
#include<future>
#include<condition_variable>
#include<filesystem>
#include<chrono>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<cinttypes>
#include<ciso646>
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
    int n , x;
    cin>>n>>x;
    vi arr(n);
    rep(i , n) cin>>arr[i];
    map<int , pair<int , int> > mp;
    rep(i,n){
        pi p;
        p.first = i+1;
        p.second = 0;
        mp[arr[i]] = p;
    }
    rep(i , n)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            if(arr[i]+arr[j]>=x) continue;
            if(mp.find(x-arr[i]-arr[j])!=mp.end() && mp[x-arr[i]-arr[j]].ff!=i+1 && mp[x-arr[i]-arr[j]].ff!=j+1)
            {
                
                cout<<i+1<<" "<<j+1<<" "<<mp[x-arr[i]-arr[j]].ff;
                return 0;
            }
        }
        for(int j = 0 ; j<i ; j++)
        {
            pi p;
            p.ff = i+1;
            p.ss = j+1;

            mp[arr[i]+arr[j]] = p;
        }
    }
    cout<<"IMPOSSIBLE";

    return 0;
}