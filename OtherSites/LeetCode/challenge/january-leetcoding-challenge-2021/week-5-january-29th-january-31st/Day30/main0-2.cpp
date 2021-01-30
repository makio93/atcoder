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
        vector<pair<int, int>> mval;
        int tnum = pnums[0].first;
        do {
            mval.emplace_back(0, 0);
            for (int i=1; i<n; ++i) {
                int vnum = pnums[i].first;
                while (vnum*2<=pnums[i].second && vnum*2<tnum) vnum *= 2;
                if (vnum*2<=pnums[i].second && abs(tnum-vnum*2)<abs(tnum-vnum)) {
                    if (vnum*2 <= tnum) mval.back().first = max(mval.back().first, abs(tnum-vnum*2));
                    else mval.back().second = max(mval.back().second, abs(tnum-vnum*2));
                }
                else {
                    if (vnum <= tnum) mval.back().first = max(mval.back().first, abs(tnum-vnum));
                    else mval.back().second = max(mval.back().second, abs(tnum-vnum));
                }
            }
            tnum *= 2;
        } while (tnum <= pnums[0].second);
        int ans = (int)(2e9);
        for (int i=0; i<(int)(mval.size()); ++i) ans = min(ans, mval[i].first+mval[i].second);
        return ans;
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
