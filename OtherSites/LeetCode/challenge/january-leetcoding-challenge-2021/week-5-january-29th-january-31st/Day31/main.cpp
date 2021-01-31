#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) sort(nums.begin(), nums.end());
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cl.nextPermutation(nums);
    for (int i=0; i<n; ++i) printf("%d%c", nums[i], (i<n-1?' ':'\n'));
    return 0;
}
