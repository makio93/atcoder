#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) 
            if (nums[i]+nums[j] == target)  return vector<int>({i, j});
        return vector<int>({-1, -1});
    }
};

int main(){
    Solution cl;
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> target;
    vector<int> ans = cl.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
