#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return (int)(distance(nums.begin(), unique(nums.begin(), nums.end())));
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    int res = cl.removeDuplicates(nums);
    cout << res << endl;
    for (int i=0; i<res; ++i) printf("%d%c", nums[i], (i<res-1?' ':'\n'));
    return 0;
}
