#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int n = nums.size(), r = n;
        for (int i=0; i<r; ++i) {
            if (nums[i] == val) {
                if (r == n) --r;
                while (r>i && nums[r]==val) --r;
                swap(nums[i], nums[r]);
            }
        }
        return r;
    }
};

int main(){
    Solution cl;
    int val, n;
    cin >> val >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    int res = cl.removeElement(nums, val);
    cout << res << endl;
    for (int i=0; i<res; ++i) printf("%d%c", nums[i], (i<res-1?' ':'\n'));
    return 0;
}
