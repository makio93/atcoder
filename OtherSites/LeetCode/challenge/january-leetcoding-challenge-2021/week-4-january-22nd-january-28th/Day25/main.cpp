#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size(), dmin = n+1, pone = -1;
        for (int i=0; i<n; ++i) {
            if (nums[i] == 1) {
                if (pone == -1) pone = i;
                else {
                    dmin = min(dmin, i-pone-1);
                    pone = i;
                }
            }
        }
        return (dmin >= k);
    }
};

int main(){
    return 0;
}
