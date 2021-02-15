#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat.front().size();
        vector<pair<int, int>> cnt(n);
        for (int i=0; i<n; ++i) cnt[i].second = i;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (mat[i][j] == 1) cnt[i].first++;
        sort(cnt.begin(), cnt.end());
        vector<int> ans(k);
        for (int i=0; i<k; ++i) ans[i] = cnt[i].second;
        return ans;
    }
};

int main(){
    return 0;
}
