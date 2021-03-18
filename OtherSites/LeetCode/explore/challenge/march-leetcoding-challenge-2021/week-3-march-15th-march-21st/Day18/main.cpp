#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> sub;
        for (int i=0; i+1<n; ++i) sub.push_back(nums[i+1]-nums[i]);
        if (sub.empty()) return res;
        int id = 0;
        while (id<(int)(sub.size()) && sub[id]==0) ++id;
        if (id < (int)(sub.size())) {
            ++res;
            int l = sub[id];
            for (int i=id+1; i<(int)(sub.size()); ++i) {
                if (sub[i]*l < 0) {
                    ++res;
                    l = sub[i];
                }
            }
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
    cout << cl.wiggleMaxLength(nums) << endl;
    return 0;
}
