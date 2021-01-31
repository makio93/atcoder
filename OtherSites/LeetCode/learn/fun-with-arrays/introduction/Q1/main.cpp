#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> runs;
        runs.emplace_back(nums.front(), 1);
        for (int i=1; i<n; ++i) {
            if (nums[i] == runs.back().first) runs.back().second++;
            else runs.emplace_back(nums[i], 1);
        }
        int mval = 0;
        for (int i=0; i<(int)(runs.size()); ++i) if (runs[i].first == 1) mval = max(mval, runs[i].second);
        return mval;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
