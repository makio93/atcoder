#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i=0; i<n; ++i) {
            int tval = nums[i], cnt = 0;
            while (tval > 0) {
                tval /= 10;
                ++cnt;
            }
            if (cnt%2 == 0) ++ans;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.findNumbers(nums) << endl;
    return 0;
}
