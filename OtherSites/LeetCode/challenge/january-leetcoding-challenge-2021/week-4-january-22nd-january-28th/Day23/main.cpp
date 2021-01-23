#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat.front().size();
        for (int i=0; i<n; ++i) {
            vector<int> changed;
            int y = i, x = 0;
            while (y<n && x<m) {
                changed.push_back(mat[y][x]);
                ++y; ++x;
            }
            sort(changed.begin(), changed.end());
            y = i, x = 0;
            for (int j=0; j<(int)(changed.size()); ++j) {
                mat[y][x] = changed[j];
                ++y; ++x;
            }
        }
        for (int i=1; i<m; ++i) {
            vector<int> changed;
            int y = 0, x = i;
            while (y<n && x<m) {
                changed.push_back(mat[y][x]);
                ++y; ++x;
            }
            sort(changed.begin(), changed.end());
            y = 0, x = i;
            for (int j=0; j<(int)(changed.size()); ++j) {
                mat[y][x] = changed[j];
                ++y; ++x;
            }
        }
        return mat;
    }
};

int main(){
    return 0;
}
