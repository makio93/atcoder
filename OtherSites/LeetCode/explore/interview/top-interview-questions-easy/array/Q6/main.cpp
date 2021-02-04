#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        map<int, pair<int, int>> cnt;
        for (int i=0; i<n; ++i) cnt[nums1[i]].first++;
        for (int i=0; i<m; ++i) cnt[nums2[i]].second++;
        vector<int> res;
        for (auto itr=cnt.begin(); itr!=cnt.end(); ++itr) {
            for (int j=0; j<min(itr->second.first,itr->second.second); ++j) res.push_back(itr->first);
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i=0; i<n; ++i) cin >> nums1[i];
    for (int i=0; i<m; ++i) cin >> nums2[i];
    vector<int> res = cl.intersect(nums1, nums2);
    int n2 = res.size();
    for (int i=0; i<n2; ++i) printf("%d%c", res[i], (i<n2-1?' ':'\n'));
    return 0;
}
