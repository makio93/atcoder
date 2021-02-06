#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        vector<long long> mval(3, (long long)(-1e15));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<3; ++j) {
                if (nums[i] > mval[j]) {
                    for (int k=2; k>=j+1; --k) mval[k] = mval[k-1];
                    mval[j] = nums[i];
                    break;
                }
                else if (nums[i] == mval[j]) break;
            }
        }
        return (int)(mval.back()!=(long long)(-1e15)?mval.back():mval.front());
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.thirdMax(nums) << endl;
    return 0;
}
