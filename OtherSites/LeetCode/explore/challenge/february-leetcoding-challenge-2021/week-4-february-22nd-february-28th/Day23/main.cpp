#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for (int i=0; i<n; ++i) {
            auto itr = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (itr!=matrix[i].end() && *itr==target) return true;
        }
        return false;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> matrix[i][j];
    int target;
    cin >> target;
    if (cl.searchMatrix(matrix, target)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
