#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size(), m = nums.size();
        bool ans = false;
        int ngr = n-1;
        for (int i=m-1; i>=0; --i) {
            if (nums[i] != groups[ngr].back()) continue;
            int ni = groups[ngr].size();
            bool ok = true;
            if (i-ni+1 < 0) ok = false;
            else {
                for (int j=0; j<ni; ++j) if (groups[ngr][ni-j-1] != nums[i-j]) ok = false;
            }
            if (ok) {
                if (ngr == 0) {
                    ans = true;
                    break;
                }
                --ngr;
                i -= ni-1;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
