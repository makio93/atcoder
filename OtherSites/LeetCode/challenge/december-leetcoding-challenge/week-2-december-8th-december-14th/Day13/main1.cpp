#include <bits/stdc++.h>
using namespace std;

// 解説を読んでから実装、AC

class Solution {
    int n2;
    vector<int> nums2;
    vector<vector<int>> dp;
    int calc(int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (r-l <= 1) return (dp[l][r] = 0);
        int eval = nums2[l] * nums2[r];
        if (r-l == 2) return (dp[l][r] = eval * nums2[l+1]);
        int res = 0;
        for (int i=l+1; i<r; ++i) res = max(res, calc(l,i)+calc(i,r)+eval*nums2[i]);
        return (dp[l][r] = res);
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums2.push_back(1);
        for (int i=0; i<n; ++i) if (nums[i] != 0) nums2.push_back(nums[i]);
        nums2.push_back(1);
        n2 = nums2.size();
        dp = vector<vector<int>>(n2, vector<int>(n2, -1));
        return calc(0, n2-1);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.maxCoins(nums) << endl;
    return 0;
}
