#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[nums[i]]++;
        int ans = 0;
        for (auto p : cnt) if (p.second == 1) ans += p.first;
        return ans;
    }
};

int main(){
    return 0;
}
