#include <bits/stdc++.h>
using namespace std;

// hintのみ見て実装、AC

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
        int mxval = 0, mnval = 0;
        for (int i=0; i<n; ++i) mxval = max(mxval, pnums[i].first);
        mnval = mxval;
        for (int i=0; i<n; ++i) mnval = min(mnval, pnums[i].first);
        int ans = mxval - mnval;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for (int i=0; i<n; ++i) que.emplace(pnums[i].first, i);
        while (!que.empty()) {
            auto pi = que.top(); que.pop();
            if (pi.first*2 <= pnums[pi.second].second) {
                que.emplace(pi.first*2, pi.second);
                mxval = max(mxval, pi.first*2);
                mnval = min(que.top().first, pi.first*2);
                ans = min(ans, mxval-mnval);
            }
            else break;
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
    cout << cl.minimumDeviation(nums) << endl;
    return 0;
}
