#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size(), cnt = 0;
        vector<int> target = heights;
        sort(target.begin(), target.end());
        for (int i=0; i<n; ++i) if (heights[i] != target[i]) ++cnt;
        return cnt;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i=0; i<n; ++i) cin >> heights[i];
    cout << cl.heightChecker(heights) << endl;
    return 0;
}
