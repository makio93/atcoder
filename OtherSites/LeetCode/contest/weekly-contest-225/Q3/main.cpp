#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix.front().size();
        vector<vector<int>> rxsum(m+1, vector<int>(n+1)), xsum(m+1, vector<int>(n+1));
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            rxsum[i+1][j+1] = (rxsum[i+1][j]) xor (matrix[i][j]);
        }
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            xsum[i+1][j+1] = (xsum[i][j+1]) xor (rxsum[i+1][j+1]);
        }
        vector<int> xlst(m*n);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            xlst[i*n+j] = xsum[i+1][j+1];
        }
        sort(xlst.rbegin(), xlst.rend());
        return xlst[k-1];
    }
};

int main(){
    return 0;
}
