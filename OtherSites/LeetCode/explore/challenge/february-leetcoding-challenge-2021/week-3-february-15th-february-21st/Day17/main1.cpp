#include <bits/stdc++.h>
using namespace std;

// 復習、わざと書いてみた総当たり、TLE

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) ans = max(ans, min(height[i],height[j])*(j-i));
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
