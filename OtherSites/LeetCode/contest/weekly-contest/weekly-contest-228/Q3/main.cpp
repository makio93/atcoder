#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        if (nums.front() == 1) return 1;
        long long l = 0, r = (long long)nums.front();
        while (r-l > 0) {
            long long c = (l + r) / 2, sum = 0;
            for (int i=0; i<n; ++i) sum += (nums[i] + (c-1)) / c - 1;
            if (sum <= (long long)(maxOperations)) r = c;
            else l = c+1;
        }
        return (int)(l);
    }
};

int main(){
    return 0;
}
