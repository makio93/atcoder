#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + nums[i];
        long long mnval = (long long)(1e15), mxval = (long long)(-1e15);
        for (int i=0; i<=n; ++i) {
            mnval = min(mnval, sum[i]);
            mxval = max(mxval, sum[i]);
        }
        return (int)(mxval-mnval);
    }
};

int main(){
    return 0;
}
