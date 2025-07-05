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
struct customer{
    int situation;
    int id;
    int room;
    int status;
};
static bool cmp(customer&a,customer&b)
{
    if(a.situation==b.situation)
    {
        return a.status>b.status;
    }
    return a.situation<b.situation;
}
signed main()
{
    fast;
    int n;
    cin>>n;
    vector<customer>lists;
    // vector<int>answer(n);
    
    rep(i,n)
    {
        int a, b;
        cin>>a>>b;
        customer c;
        c.situation = a;
        c.id = i;
        c.room = 0;
        c.status = 1;
        lists.push_back(c);
        
        c.situation = b;
        c.id = i;
        c.room = 0;
        c.status = 0;
        lists.push_back(c);
        
        
    }
    sort(lists.begin() , lists.end() , cmp);
    priority_queue<int,vector<int>,greater<int> >pq;
    f(i ,1 , n+1)pq.push(i);
    vector<int>rooms(n);
    int answer = INT_MIN;
    for(int i = 0 ; i < lists.size() ; i++){
        if(lists[i].status == 1){
            answer = max(answer , pq.top());
            lists[i].room = pq.top();
            rooms[lists[i].id] = pq.top();
            pq.pop();
        }
        else{
            pq.push(rooms[lists[i].id]);
        }
    }
    cout<<answer<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<rooms[i]<<" ";
    }
    return 0;
}