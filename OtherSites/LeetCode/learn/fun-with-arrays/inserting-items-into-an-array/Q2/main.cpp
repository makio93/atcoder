#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=0; i<n; ++i) nums1[m+i] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};

int main(){
    Solution cl;
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i=0; i<m; ++i) cin >> nums1[i];
    for (int i=0; i<n; ++i) cin >> nums2[i];
    cl.merge(nums1, m-n, nums2, n);
    for (int i=0; i<m; ++i) printf("%d%c", nums1[i], (i<m-1?' ':'\n'));
    return 0;
}
