#include <bits/stdc++.h>
using namespace std;

// 自力ACぶん、空間計算量O(1)での解法

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals(1, nums.front());
        bool ans = false;
        for (int i=1; i<n; ++i) {
            if (vals.size() == 2) {
                if (nums[i] > vals[1]) {
                    ans = true;
                    break;
                }
            }
            if (vals.size() == 1) {
                if (nums[i] > vals[0]) vals.push_back(nums[i]);
                else vals[0] = nums[i];
            }
            else {
                if (nums[i] <= vals[0]) vals[0] = nums[i];
                else if (nums[i] <= vals[1]) vals[1] = nums[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    if (cl.increasingTriplet(nums)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
