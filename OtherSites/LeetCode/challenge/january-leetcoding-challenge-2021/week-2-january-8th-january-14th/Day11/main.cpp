#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int extra = max(0, (int)(nums1.size())-m);
        for (int i=0; i<extra; ++i) nums1.pop_back();
        for (int i=0; i<n; ++i) nums1.push_back(nums2[i]);
        sort(nums1.begin(), nums1.end());
    }
};

int main(){
    
    return 0;
}
