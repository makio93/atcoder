#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i=0; i<n; ++i) res[nums[i]-1]++;
        int pos = 0;
        for (int i=0; i<n; ++i) {
            if (res[i] == 0) {
                res[pos] = i+1;
                ++pos;
            }
        }
        res.erase(res.begin()+pos, res.end());
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    vector<int> ans = cl.findDisappearedNumbers(nums);
    int n2 = ans.size();
    for (int i=0; i<n2; ++i) printf("%d%c", ans[i], (i<n2-1?' ':'\n'));
    return 0;
}
