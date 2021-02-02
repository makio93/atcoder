#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), id = 0;
        for (int i=0; i<n; ++i) {
            if (i==n-1 || nums[i+1]!=nums[i]) {
                swap(nums[i], nums[id]);
                ++id;
            }
        }
        return id;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    int res = cl.removeDuplicates(nums);
    cout << res << endl;
    for (int i=0; i<res; ++i) printf("%d%c", nums[i], (i<res-1?' ':'\n'));
    return 0;
}
