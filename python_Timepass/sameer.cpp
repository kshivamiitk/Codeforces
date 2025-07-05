#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
unordered_map<string, int> memo;
string rmc(string s) {
    for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() && s[j] == s[i])
            j++;
        if (j - i >= 3) {
            string ns = s.substr(0, i) + s.substr(j);
            return rmc(ns);
        }
        else
            i = j;
    }
    return s;
}
int dfs(string s, vector<int>& h) {
    s = rmc(s);
    if (s.empty())
        return 0;
    string key = s;
    key.push_back('#');
    for (int x : h)
        key += to_string(x) + ",";
    if (memo.count(key))
        return memo[key];
    int ans = inf;
    for (int i = 0; i <= s.size(); i++) {
        for (int c = 0; c < 5; c++) {
            if (h[c] == 0)
                continue;
            char ch;
            if (c == 0)ch = 'R';
            else if (c == 1)ch = 'Y';
            else if (c == 2)ch = 'B';
            else if (c == 3)ch = 'G';
            else  ch = 'W';
            if (i > 0 && s[i - 1] == ch)
                continue;
            string ns = s.substr(0, i) + ch + s.substr(i);
            h[c]--;
            int stp = dfs(ns, h);
            if (stp != inf)
                ans = min(ans, stp + 1);
            h[c]++;
        }
    }
    memo[key] = ans;
    return ans;
}
int fms(string s, string hnd) {
    vector<int> h(5, 0);
    for (char c : hnd) {
        int idx;
        if (c == 'R')idx = 0;
        else if (c == 'Y')idx = 1;
        else if (c == 'B') idx = 2;
        else if (c == 'G')idx = 3;
        else idx = 4;
        h[idx]++;
    }
    memo.clear();
    int res = dfs(s, h);
    return res == inf ? -1 : res;
}
int main() {
    string brd, hnd;
    cin >> brd >> hnd;
    int r = fms(brd, hnd);
    cout << r;
    return 0;
}
