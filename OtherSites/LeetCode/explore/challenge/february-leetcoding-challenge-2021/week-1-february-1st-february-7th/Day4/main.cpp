#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[nums[i]]++;
        int ans = 0;
        for (auto itr=cnt.begin(); itr!=cnt.end(); ++itr) {
            if (cnt.find(itr->first+1) != cnt.end()) ans = max(ans, (itr->second)+cnt[itr->first+1]);
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
    cout << cl.findLHS(nums) << endl;
    return 0;
}
