#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int x;
    
    vector<string> lines = {
        "CODEFORCES",  // 1
        "EYE",         // 2
        "TESTING",     // 3
        "SYSTEM",      // 4
        "APRIL",       // 5
        "FOOLS",       // 6
        "2025",        // 7 
        "IS",          // 8 
        "ALMOST",      // 9 
        "HERE",        // 10 
        "!"            // 11 
    };
    
    cout << lines[x - 1] << endl;
    
    return 0;
}
