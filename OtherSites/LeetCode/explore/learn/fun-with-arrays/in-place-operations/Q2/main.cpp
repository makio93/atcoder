#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i = 0, r = 0;
        while (i<n && r<n) {
            while (r+1<n && nums[r+1]==nums[r]) ++r;
            swap(nums[i], nums[r]);
            ++i; ++r;
        }
        return i;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    int len = cl.removeDuplicates(nums);
    for (int i=0; i<len; ++i) printf("%d%c", nums[i], (i<len-1?' ':'\n'));
    return 0;
}
