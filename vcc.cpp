#include<iostream>
#include<vector>
using namespace std;
int func(int a){
    // define this function either cubic logrithmic
    return log2(a) *(a - 1) / (a);
}
bool cmp(int a , int b){
 return func(a) < func(b);
}
int main(){
    int n ;
    cin >> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    // order nlogn wala sort
    for(int i = 0 ; i < n ; i++){
        cout << func(arr[i]) << " ";
    }
    cout << endl;
    sort(arr.begin() , arr.end() , cmp);
    for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;
}