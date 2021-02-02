#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k > 0) {
            reverse(nums.begin(), nums.end());
            nums.insert(nums.end(), nums.begin(), nums.begin()+k);
            reverse(nums.begin(), nums.end());
            nums.erase(nums.begin()+n, nums.end());
        }
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> k;
    cl.rotate(nums, k);
    for (int i=0; i<n; ++i) printf("%d%c", nums[i], (i<n-1?' ':'\n'));
    return 0;
}
