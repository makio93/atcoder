#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans = nums.front();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            bool ok = false;
            if (i-1>=0 && nums[i-1]==nums[i]) ok = true;
            if (i+1<n && nums[i+1]==nums[i]) ok = true;
            if (!ok) {
                ans = nums[i];
                break;
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
    cout << cl.singleNumber(nums) << endl;
    return 0;
}
