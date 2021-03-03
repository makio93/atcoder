#include <bits/stdc++.h>
using namespace std;

// O(n),O(1)解答、follow up解法

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            int val = nums[i]>=0 ? nums[i] : -(nums[i]+1);
            if (val < n) nums[val] = -nums[val] - 1;
        }
        int res = n;
        for (int i=0; i<n; ++i) if (nums[i] >= 0) res = i;
        return res;
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
