#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), zero = -1;
        for (int i=0; i<n; ++i) {
            if (nums[i]==0) { if (zero==-1) zero = i; }
            else if (zero != -1) {
                swap(nums[i], nums[zero]);
                ++zero;
            }
        }
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cl.moveZeroes(nums);
    for (int i=0; i<n; ++i) printf("%d%c", nums[i], (i<n-1?' ':'\n'));
    return 0;
}
