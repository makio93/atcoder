#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pnums(n);
        for (int i=0; i<n; ++i) {
            pnums[i].second = nums[i];
            if (nums[i]%2 == 1) pnums[i].second *= 2;
            while (nums[i]%2==0) nums[i] /= 2;
            pnums[i].first = nums[i];
        }
        sort(pnums.begin(), pnums.end());
        int mvalp = 0, mvaln = 0, mval2p = 0, mval2n = 0;
        for (int i=0; i<n-1; ++i) {
            int vnum = pnums[i].first;
            int tval = (int)(2e9);
            while (vnum<=pnums[i].second && vnum<=pnums[n-1].first) {
                tval = min(tval, abs(vnum-pnums[n-1].first));
                vnum *= 2;
            }
            mval = max(mval, tval);
            vnum = pnums[i].first;
            tval = (int)(2e9);
            while (vnum<=pnums[i].second && vnum<=pnums[n-1].second) {
                tval = min(tval, abs(vnum-pnums[n-1].second));
                vnum *= 2;
            }
            mval2 = max(mval2, tval);
        }
        return min(mval, mval2);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.minimumDeviation(nums) << endl;
    return 0;
}
