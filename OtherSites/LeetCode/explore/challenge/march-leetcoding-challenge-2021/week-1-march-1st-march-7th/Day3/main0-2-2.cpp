#include <bits/stdc++.h>
using namespace std;

// O(n),O(1)解答、follow up解法
// さらにメモリをなるべく削ろうとしてみた

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int d = 0, i = 0;
        for (i=0; i<nums.size(); ++i) {
            d = nums[i]>=0 ? nums[i] : -(nums[i]+1);
            if (d < nums.size()) nums[d] = -nums[d] - 1;
        }
        for (i=0; i<nums.size(); ++i) if (nums[i] >= 0) return i;
        return (int)nums.size();
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.missingNumber(nums) << endl;
    return 0;
}
