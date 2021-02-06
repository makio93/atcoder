#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> mval = { (int)(1e9), -1 };
        for (int i=0; i<n; ++i) mval = min(mval, { abs(nums[i]), i });
        int l = mval.second, r = mval.second, id = 1;
        vector<int> res(n);
        res.front() = nums[l] * nums[l];
        while (id < n) {
            int nval = 0;
            if (l-1>=0 && r+1<n) {
                if (abs(nums[l-1]) <= abs(nums[r+1])) {
                    --l;
                    nval = nums[l];
                }
                else {
                    ++r;
                    nval = nums[r];
                }
            }
            else if (l-1>=0) {
                --l;
                nval = nums[l];
            }
            else if (r+1<n) {
                ++r;
                nval = nums[r];
            }
            res[id] = nval * nval;
            ++id;
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    vector<int> ans = cl.sortedSquares(nums);
    for (int i=0; i<n; ++i) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
