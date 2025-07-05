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
    string s;
    cin >> s;
    vector<int>arr(26);
    for(int i = 0 ; i < s.size() ; i++) arr[s[i] - 'A']++;
    int odd = 0;
    for(int i = 0 ; i < 26 ; i++) if(arr[i] % 2) odd++;
    if(odd > 1) cout<<"NO SOLUTION"<<endl;
    else{
        string ans = "";
        for(int i = 0 ; i < 26 ; i++){
            if(arr[i] % 2 == 0){
                for(int j = 0 ; j < arr[i] / 2 ; j++) ans += (char)(i + 'A');
            }
        }
        cout<<ans;
        for(int i = 0 ; i < 26 ; i++){
            if(arr[i] % 2){
                for(int j = 0 ; j < arr[i] ; j++) cout<<(char)(i + 'A');
            }
        }
        reverse(ans.begin() , ans.end());
        cout<<ans<<endl;
    }
    
    return 0;
}