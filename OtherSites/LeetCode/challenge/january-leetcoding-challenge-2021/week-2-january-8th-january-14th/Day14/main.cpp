#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        set<pair<int, int>> search;
        int sum = 0;
        search.emplace(0, n);
        for (int i=n-1; i>=0; --i) {
            sum += nums[i];
            search.emplace(sum, i);
        }
        int ans = n+1;
        auto itr = search.upper_bound({x,n+1});
        --itr;
        if (itr->first == x) ans = min(ans, n-(itr->second));
        for (int i=0; i<n; ++i) {
            x -= nums[i];
            if (x < 0) break;
            auto itr = search.upper_bound({x,n+1});
            --itr;
            if (itr->first==x && itr->second>i) ans = min(ans, (i+1)+n-(itr->second));
        }
        if (ans == n+1) ans = -1;
        return ans;
    }
};

int main(){
    
    return 0;
}
