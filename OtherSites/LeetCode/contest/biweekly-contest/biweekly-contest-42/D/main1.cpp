#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> id;
        for (int i=0; i<n; ++i) if (nums[i] == 1) id.push_back(i);
        int m = id.size();
        vector<long long> sid(m+1);
        for (int i=0; i<m; ++i) sid[i+1] = sid[i] + id[i];
        long long mval = (long long)(1e18);
        for (int i=0; i+k<=m; ++i) {
            long long cval = (long long)(id[i+(k+1)/2-1]-id[i])*((k+1)/2)-(sid[i+(k+1)/2]-sid[i+1]-(long long)id[i]*((k+1)/2-1)) + (sid[i+k]-sid[i+(k+1)/2])-(long long)(id[i+(k+1)/2-1])*(k-(k+1)/2);
            mval = min(mval, cval);
        }
        long long sub = (k%2==0) ? ((long long)(k/2)*(k/2+1)-k/2) : ((long long)((k-1)/2)*((k-1)/2+1));
        mval -= sub;
        return (int)mval;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cin >> k;
    cout << cl.minMoves(nums, k) << endl;
    return 0;
}
