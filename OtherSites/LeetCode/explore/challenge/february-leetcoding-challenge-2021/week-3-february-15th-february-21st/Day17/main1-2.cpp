#include <bits/stdc++.h>
using namespace std;

// 復習、解説の解法での解答

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r = n-1;
        while (r-l >= 1) {
            ans = max(ans, (r-l)*min(height[l],height[r]));
            if (height[l] < height[r]) ++l;
            else if (height[l] > height[r]) --r;
            else { ++l; --r; }
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i=0; i<n; ++i) cin >> height[i];
    cout << cl.maxArea(height) << endl;
    return 0;
}
