#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        if (matrix[0].empty()) return res;
        for (int i=0; i<=m+n-2; ++i) {
            int i2, j2, di, dj;
            if (i%2==0) {
                i2 = min(m-1, i);
                j2 = i - i2;
                di = -1;
                dj = 1;
            }
            else {
                j2 = min(n-1, i);
                i2 = i - j2;
                di = 1;
                dj = -1;
            }
            while (i2>=0 && i2<m && j2>=0 && j2<n) {
                res.push_back(matrix[i2][j2]);
                i2 += di;
                j2 += dj;
            }
        }
        return res;
    }
};

int main() {
    Solution cl;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) cin >> matrix[i][j];
    auto res = cl.findDiagonalOrder(matrix);
    for (int i=0; i<m*n; ++i) printf("%d%c", res[i], ((i<m*n-1)?' ':'\n'));
    return 0;
}
