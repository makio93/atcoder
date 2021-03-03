#include <bits/stdc++.h>
using namespace std;

// O(n),O(n)解答、通常の解法

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n+1);
        for (int i=0; i<n; ++i) cnt[nums[i]]++;
        int res = -1;
        for (int i=0; i<=n; ++i) if (cnt[i] == 0) res = i;
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.missingNumber(nums) << endl;
    return 0;
}
