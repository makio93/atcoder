#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i=0; i<n; ++i) ans[i] = nums[i] * nums[i];
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    vector<int> res = cl.sortedSquares(nums);
    for (int i=0; i<n; ++i) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    return 0;
}
