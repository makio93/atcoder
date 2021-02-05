#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), r = n-1;
        if (n == 0) return n;
        for (int i=0; i<n; ++i) {
            if (r <= i) break;
            if (nums[i] == val) {
                while (r-1>=i && nums[r]==val) --r;
                if (r == i) break;
                swap(nums[i], nums[r]);
            }
        }
        if (r==n-1 && nums[r]!=val) r = n;
        return r;
    }
};

int main(){
    Solution cl;
    int n, val;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> val;
    int len = cl.removeElement(nums, val);
    for (int i=0; i<len; ++i) printf("%d%c", nums[i], (i<len-1?' ':'\n'));
    return 0;
}
