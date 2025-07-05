#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define vi vector<int>
#define vpi vector<pair<int, int> >
#define pi pair<int, int>

struct FenwickTree {
    vi bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void compressCoordinates(vpi &ranges, vi &compressed) {
    vi endpoints;
    for (auto &range : ranges) {
        endpoints.push_back(range.first);
        endpoints.push_back(range.second);
    }
    sort(endpoints.begin(), endpoints.end());
    endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());

    for (auto &range : ranges) {
        range.first = lower_bound(endpoints.begin(), endpoints.end(), range.first) - endpoints.begin();
        range.second = lower_bound(endpoints.begin(), endpoints.end(), range.second) - endpoints.begin();
    }

    compressed = endpoints;
}

bool cmp(const pi &a, const pi &b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vpi ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    vi compressed;
    compressCoordinates(ranges, compressed);

    sort(ranges.begin(), ranges.end(), cmp);

    vi containedWithin(n), containsOthers(n);
    FenwickTree fenwick(compressed.size());

    // Compute containedWithin
    for (int i = n - 1; i >= 0; --i) {
        containedWithin[i] = fenwick.query(ranges[i].second - 1);
        fenwick.update(ranges[i].second, 1);
    }

    // Reinitialize Fenwick Tree
    fenwick = FenwickTree(compressed.size());

    // Compute containsOthers
    for (int i = 0; i < n; ++i) {
        containsOthers[i] = fenwick.rangeQuery(ranges[i].second + 1, compressed.size() - 1);
        fenwick.update(ranges[i].second, 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << containedWithin[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << containsOthers[i] << " ";
    }
    cout << endl;

    return 0;
}
