#include <bits/stdc++.h>
using namespace std;

// 解説を見て、時間計算量O(n)かつ空間計算量O(1)の方法、線形探索のみで実装

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), lval = (int)(1e9), rval = (int)(-1e9);
        for (int i=1; i<n; ++i) if (nums[i-1] > nums[i]) lval = min(lval, nums[i]);
        for (int i=n-2; i>=0; --i) if (nums[i+1] < nums[i]) rval = max(rval, nums[i]);
        if (lval == (int)(1e9)) return 0;
        int l = n, r = -1;
        for (int i=0; i<n; ++i) if (nums[i] > lval) l = min(l, i);
        for (int i=0; i<n; ++i) if (nums[i] < rval) r = max(r, i);
        return (r-l+1);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.findUnsortedSubarray(nums) << endl;
    return 0;
}
