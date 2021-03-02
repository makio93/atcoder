#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1);
        for (int i=0; i<n; ++i) cnt[nums[i]]++;
        vector<int> res(2);
        for (int i=1; i<=n; ++i) {
            if (cnt[i] == 2) res[0] = i;
            if (cnt[i] == 0) res[1] = i;
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    auto res = cl.findErrorNums(nums);
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}
