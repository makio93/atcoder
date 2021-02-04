#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        int n = nums.size();
        set<int> vals;
        for (int i=0; i<n; ++i) {
            if (vals.find(nums[i]) != vals.end()) return true;
            vals.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    if (cl.containsDuplicate(nums)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
