#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        for (int i=0; i<n-1; ++i) for (int j=i+1; j<n; ++j) {
            cnt[nums[i]*nums[j]]++;
        }
        int ans = 0;
        for (auto p : cnt) {
            if (p.second <= 1) continue;
            ans += p.second * (p.second-1) / 2 * 8;
        }
        return ans;
    }
};

int main(){

    return 0;
}
