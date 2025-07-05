#include <iostream>
#include <queue>

#define ll long long int
using namespace std;

void solve(ll N , int k)
{
    queue<ll> q;
    // Push all the children to the queue
    for (int i = 1; i <= N; i++)
        q.push(i);

    // Set the flag to false, so that the first child does
    // not get removed
    bool flag = 1;

    while (!q.empty()) {
        int ele = q.front();
        q.pop();
        // If we have to remove the element, print it
        if (!flag) {
            cout << ele << " ";
        }
        // If we don't have to remove the element, push it
        // back to the queue
        else {
            if(q.size() < k){
                cout<<ele<<" ";

            }
            else q.push(ele);
        }
        // Toggle the value of flag so that only the
        // alternate elements get removed
        flag = (flag+1)%k;
    }
}

int main()
{
    ll N ;
    cin >> N;
    int k ;
    cin >> k;
    solve(N , k+1);
}
