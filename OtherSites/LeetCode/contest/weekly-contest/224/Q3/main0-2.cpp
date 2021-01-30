#include <bits/stdc++.h>
using namespace std;

// 本番終了後、自力研究、自力AC

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<vector<int>> sum(n+1, vector<int>(m));
        for (int i=0; i<m; ++i) for (int j=n-1; j>=0; --j) {
            if (matrix[j][i] == 1) sum[j][i] = sum[j+1][i] + 1;
            else sum[j][i] = 0;
        }
        int ans = 0;
        for (int i=0; i<n; ++i) {
            map<int, int> scnt;
            for (int j=0; j<m; ++j) scnt[sum[i][j]]++;
            int nlen = 0;
            for (auto itr=scnt.rbegin(); itr!=scnt.rend(); ++itr) {
                if (itr->first == 0) break;
                nlen += itr->second;
                ans = max(ans, nlen*(itr->first));
            }
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> matrix[i][j];
    cout << cl.largestSubmatrix(matrix) << endl;
    return 0;
}
