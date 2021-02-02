#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
        vector<vector<int>> res(n, vector<int>(n));
        int vy = 0, vx = 0, dir = 0;
        for (int i=1; i<=n*n; ++i) {
            res[vy][vx] = i;
            int ny = vy + dy[dir], nx = vx + dx[dir];
            if (i+1 <= n*n) {
                if (ny<0 || ny>=n || nx<0 || nx>=n || res[ny][nx]!=0) {
                    dir = (dir+1) % 4;
                    ny = vy + dy[dir]; nx = vx + dx[dir];
                }
            }
            vy = ny; vx = nx;
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<vector<int>> res = cl.generateMatrix(n);
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) printf("%d%c", res[i][j], (j<n-1?' ':'\n'));
    return 0;
}
