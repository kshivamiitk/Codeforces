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
#include<numeric>
#include<string>

using namespace std;
typedef long long int ll;
#define MAP map<int,int>
#define mod 1000000007
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define f(i,a,b) for(int i(a); i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define pi pair<int,int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mt make_tuple
#define pq priority_queue
#define pqv priority_queue<int, vector<int>, greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf 1e18
#define ninf -1e18
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

bool find(string s , string t){
    // check if t is a substring of s or not
    
    if(s.find(t) != std::string::npos){
        return true;
    }
    else return false;
}
void solve(){
    int n; cin >> n ;
    string s; 
    cin >> s;
    for(char c = 'a' ; c <= 'z' ; c++){
        bool found = false;
        rep(i , n) if(s[i] == c){found = true; break;}
        if(!found){
            cout << c << endl;
            return ;
        }
    }
    for(char c = 'a' ; c <= 'z' ; c++){
        string t;
        t += c;
        for(char d = 'a' ; d <= 'z' ; d++){
            string temp = t;
            temp += d;
            if(find(s , temp)) continue;
            else{
                cout << temp << endl;
                return ;
            }
        }
    }
    for(char c = 'a' ; c <= 'z' ; c++){
        string t ;
        t += c ;
        for(char d = 'a' ; d <= 'z' ; d++){
            string x = t;
            x += d;
            for(char e = 'a' ; e <= 'z' ; e++){
                string y = x;
                y += e;
                if(!find(s , y)){
                    cout << y << endl;
                    return ;
                }
            }
        }
    }
}
signed main(){
    fast;
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}