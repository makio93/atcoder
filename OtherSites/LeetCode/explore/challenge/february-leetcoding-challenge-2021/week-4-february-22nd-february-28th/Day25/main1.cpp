#include <bits/stdc++.h>
using namespace std;

// 解説を見て、時間計算量O(n)の方法、スタックを使う

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> sid;
        int n = nums.size(), l = n, r = -1;
        for (int i=0; i<n; ++i) {
            if (sid.empty() || nums[sid.top()]<=nums[i]) sid.push(i);
            else {
                while (!sid.empty()&&nums[sid.top()]>nums[i]) sid.pop();
                if (sid.empty()) l = min(l, 0);
                else l = min(l, sid.top()+1);
            }
        }
        while (!sid.empty()) sid.pop();
        for (int i=n-1; i>=0; --i) {
            if (sid.empty() || nums[sid.top()]>=nums[i]) sid.push(i);
            else {
                while (!sid.empty()&&nums[sid.top()]<nums[i]) sid.pop();
                if (sid.empty()) r = max(r, n-1);
                else r = max(r, sid.top()-1);
            }
        }
        return max(0, r-l+1);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.findUnsortedSubarray(nums) << endl;
    return 0;
}
