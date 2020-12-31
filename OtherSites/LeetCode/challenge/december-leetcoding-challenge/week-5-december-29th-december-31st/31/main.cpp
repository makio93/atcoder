#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<pair<long long, int>> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<pair<long long, int>>(2*n-1, {(long long)(1e18), -1});
    }
    void update(int k, int a) {
        int k_ = k;
        k += n-1;
        dat[k] = {a, k_};
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    pair<long long, int> query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return {(long long)(1e18), -1};
        if (a<=l && r<=b) return dat[k];
        else {
            pair<long long, int> vl = query(a, b, k*2+1, l, (l+r)/2);
            pair<long long, int> vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
SegmentTree* psgt;

long long search(int l, int r) {
    if (r-l == 0) return 0;
    pair<long long, int> val = psgt->query(l, r);
    if (r-l == 1) return val.first;
    int c = val.second;
    long long res = (r-l) * val.first;
    long long lres = search(l, c), rres = search(c+1, r);
    res = max(res, max(lres, rres));
    return res;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        SegmentTree segt(n);
        for (int i=0; i<n; ++i) segt.update(i, heights[i]);
        psgt = &segt;
        long long res = search(0, n);
        return (int)res;
    }
};

int main() {
    Solution cl;
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i=0; i<n; ++i) cin >> heights[i];
    int res = cl.largestRectangleArea(heights);
    cout << res << endl;
    return 0;
}
