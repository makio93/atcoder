#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), id = 0;
        for (int i=0; i<n; ++i) {
            if (nums[id] == val) nums.erase(nums.begin()+id);
            else ++id;
        }
        return (int)(nums.size());
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
