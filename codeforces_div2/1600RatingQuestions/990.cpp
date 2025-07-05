#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
#define int long long 
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define f(i,a,b) for(int i=(a); i<(b); i++)
#define rep(i,n) for(int i=0; i<(n); i++)
 
// Global vector initialized with -1s
vector<int> arr(500, -1);
 
// This function computes the next term of the look‐and‐say sequence.
// It assumes that the valid part of 'arr' is stored at the beginning and terminated by -1.
void func(vector<int>& arr, int n) {
    // Base cases for the look-and-say sequence.
    if(n == 1) {
        arr[0] = 1;
        // Reset the rest to -1
        f(i, 1, 500) arr[i] = -1;
        return;
    }
    if(n == 2) {
        arr[0] = arr[1] = 1;
        f(i, 2, 500) arr[i] = -1;
        return;
    }
    
    // Recursively generate the (n-1)th term.
    func(arr, n - 1);
    
    // Determine the length of the current sequence.
    int len = 0;
    while(len < (int)arr.size() && arr[len] != -1)
        len++;
    
    // Build the next sequence by reading off groups.
    vi temp;
    int count = 1;
    // Iterate from 0 to len-2 to compare arr[i] and arr[i+1]
    f(i, 0, len - 1) {
        if(arr[i] == arr[i + 1]) {
            count++;
        } else {
            temp.pb(count);
            temp.pb(arr[i]);
            count = 1;
        }
    }
    // Process the final group (the last element at index len-1)
    temp.pb(count);
    temp.pb(arr[len - 1]);
    
    // Copy the new sequence back into arr and reset the remaining elements to -1.
    rep(i, (int)temp.size()) {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < (int)arr.size(); i++) {
        arr[i] = -1;
    }
}
 
signed main(){
    int tc;
    cin >> tc;
    while(tc--){
    int n;
    cin >> n;
    func(arr, n);
    // Output the first 10 elements of the generated sequence
    int i = 0;
    while(arr[i] != -1){
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;
    }
    return 0;
}
