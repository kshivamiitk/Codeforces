// this is there to explain the concepts of fenwick tree
// Fenwick tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.
// It is also known as a binary indexed tree.
// The tree is constructed in such a way that the value of each node is the sum of the values of the nodes in the subtree rooted at that node.
// The tree is constructed in such a way that the value of each node is the sum of the values of the nodes in the subtree rooted at that node.
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
    fast;
    int n;
    cin>>n;
    vi a(n);
    rep(i,n) cin>>a[i];
    vi fenwick(n+1,0);
    auto update=[&](int i,int val)
    {
        for(;i<=n;i+=i&-i)
        {
            fenwick[i]+=val;
        }
    };
    auto query=[&](int i)
    {
        int sum=0;
        for(;i>0;i-=i&-i)
        {
            sum+=fenwick[i];
        }
        return sum;
    };
    rep(i,n)
    {
        update(i+1,a[i]);
    }
    cout<<query(5)<<endl;
    cout<<query(6)<<endl;
    return 0;
}