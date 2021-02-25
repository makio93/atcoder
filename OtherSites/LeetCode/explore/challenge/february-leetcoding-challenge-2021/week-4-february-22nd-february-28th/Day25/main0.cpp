#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), l = n, r = 0;
        for (int i=0; i<n; ++i) {
            if (sorted[i] != nums[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        return max(0, r-l+1);
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
