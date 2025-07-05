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
//oset<int>s:s.find_by_order(k):Kth element in ,s.order_of_key(k):Number of item strictly lessthan k
//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
signed main()
{
    int n ;
    cin>>n;
    vi arr(n);
    rep(i , n) cin>>arr[i];
    stack<int> s;
    vi ans(n);
    //nearest value to its left with 1 base index
    for(int i = 0 ; i < n ; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if(s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top() + 1;
        s.push(i);
    }
    rep(i , n) cout<<ans[i]<<" ";
    return 0;
}