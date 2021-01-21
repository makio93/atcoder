#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct SegmentTree {
        int n;
        vector<pair<int,int>> dat;
        SegmentTree() { init(1); }
        SegmentTree(int n_) { init(n_); }
        void init(int n_) {
            n = 1;
            while (n < n_) n *= 2;
            dat = vector<pair<int,int>>(2*n-1, {(int)(1e9),n+1});
        }
        void update(int k, int a) {
            int id = k;
            k += n-1;
            dat[k] = {a,id};
            while (k > 0) {
                k = (k-1) / 2;
                dat[k] = min(dat[k*2+1], dat[k*2+2]);
            }
        }
        pair<int,int> query(int a, int b, int k=0, int l=0, int r=-1) {
            if (r == -1) { r = n; k = 0; l = 0; }
            if (r<=a || b<=l) return {(int)(1e9),n+1};
            if (a<=l && r<=b) return dat[k];
            else {
                pair<int,int> vl = query(a, b, k*2+1, l, (l+r)/2);
                pair<int,int> vr = query(a, b, k*2+2, (l+r)/2, r);
                return min(vl, vr);
            }
        }
    };
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree st(n);
        for (int i=0; i<n; ++i) st.update(i, nums[i]);
        vector<int> res;
        int last = 0;
        for (int i=n-k+1; i<=n; ++i) {
            auto val = st.query(last, i);
            res.push_back(val.first);
            last = val.second + 1;
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> k;
    auto ans = cl.mostCompetitive(nums, k);
    for (int i=0; i<k; ++i) printf("%d%c", ans[i], (i<k-1?' ':'\n'));
    return 0;
}
