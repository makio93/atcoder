#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> dp(m, vector<int>(m, (int)(-1e9))), ndp;
        dp[0][m-1] = 0;
        for (int i=0; i<n; ++i) {
            const vector<int> dj = { -1, 0, 1 };
            ndp = vector<vector<int>>(m, vector<int>(m, (int)(-1e9)));
            for (int j1=0; j1<m; ++j1) for (int j2=0; j2<m; ++j2) {
                if (dp[j1][j2] == (-1e9)) continue;
                int nval = dp[j1][j2] + grid[i][j1];
                if (j1 != j2) nval += grid[i][j2];
                for (int i1=0; i1<3; ++i1) for (int i2=0; i2<3; ++i2) {
                    int nj1 = j1 + dj[i1], nj2 = j2 + dj[i2];
                    if (nj1<0 || nj1>=m || nj2<0 || nj2>=m) continue;
                    ndp[nj1][nj2] = max(ndp[nj1][nj2], nval);
                }
            }
            swap(dp, ndp);
        }
        int ans = 0;
        for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) ans = max(ans, dp[i][j]);
        return ans;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> grid[i][j];
    cout << cl.cherryPickup(grid) << endl;
    return 0;
}
