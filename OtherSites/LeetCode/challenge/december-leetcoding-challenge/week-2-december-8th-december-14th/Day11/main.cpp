#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), cnt = 0, i = 0;
        for (int r=0; r<n; ++r) {
            if (cnt<2) {
                nums[i] = nums[r];
                ++i;
            }
            if (r+1<n && nums[r+1]==nums[r]) ++cnt;
            else cnt = 0;
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
    cout << len << endl;
    for (int i=0; i<len; ++i) printf("%d%c", nums[i], (i<len-1?' ':'\n'));
    return 0;
}
