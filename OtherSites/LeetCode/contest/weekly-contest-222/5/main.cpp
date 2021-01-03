#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + nums[i];
        long long res = 0, mod = (long long)(1e9+7);
        for (int i=1; i<n-1; ++i) {
            long long ltar = sum[i] * 2, rtar = (sum[n] - sum[i]) / 2 + sum[i];
            int ld = distance(sum.begin(), lower_bound(sum.begin(), sum.end(), ltar));
            int rd = distance(sum.begin(), upper_bound(sum.begin(), sum.end(), rtar));
            if (rd<=i) continue;
            ld = max(ld, i+1);
            rd = min(rd, n);
            if (rd <= ld) continue;
            res = (res + (rd-ld)) % mod;
        }
        return (int)(res);
    }
};


int main(){
    return 0;
}
