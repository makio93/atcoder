#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[nums[i]]++;
        int ans = 0;
        for (auto p : cnt) {
            if (p.first < k-p.first) {
                if (cnt.find(k-p.first) != cnt.end()) ans += min(p.second, cnt[k-p.first]);
            }
            else if (p.first == k-p.first) ans += p.second / 2;
            else break;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
