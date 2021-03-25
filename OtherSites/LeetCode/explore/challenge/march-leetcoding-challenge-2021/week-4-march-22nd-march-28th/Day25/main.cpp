#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<vector<int>>();
        int n = matrix.size(), m = matrix.front().size();
        vector<vector<bool>> pac(n, vector<bool>(m)), atl(n, vector<bool>(m));
        vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        for (int i=0; i<m; ++i) {
            if (pac[0][i]) continue;
            queue<pair<int, int>> que;
            que.emplace(0, i);
            pac[0][i] = true;
            while (!que.empty()) {
                auto pi = que.front(); que.pop();
                int y = pi.first, x = pi.second, d = matrix[y][x];
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if (pac[ny][nx]) continue;
                    if (matrix[ny][nx] < d) continue;
                    que.emplace(ny, nx);
                    pac[ny][nx] = true;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (pac[i][0]) continue;
            queue<pair<int, int>> que;
            que.emplace(i, 0);
            pac[i][0] = true;
            while (!que.empty()) {
                auto pi = que.front(); que.pop();
                int y = pi.first, x = pi.second, d = matrix[y][x];
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if (pac[ny][nx]) continue;
                    if (matrix[ny][nx] < d) continue;
                    que.emplace(ny, nx);
                    pac[ny][nx] = true;
                }
            }
        }
        for (int i=0; i<m; ++i) {
            if (atl[n-1][i]) continue;
            queue<pair<int, int>> que;
            que.emplace(n-1, i);
            atl[n-1][i] = true;
            while (!que.empty()) {
                auto pi = que.front(); que.pop();
                int y = pi.first, x = pi.second, d = matrix[y][x];
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if (atl[ny][nx]) continue;
                    if (matrix[ny][nx] < d) continue;
                    que.emplace(ny, nx);
                    atl[ny][nx] = true;
                }
            }
        }
        for (int i=0; i<n; ++i) {
            if (atl[i][m-1]) continue;
            queue<pair<int, int>> que;
            que.emplace(i, m-1);
            atl[i][m-1] = true;
            while (!que.empty()) {
                auto pi = que.front(); que.pop();
                int y = pi.first, x = pi.second, d = matrix[y][x];
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                    if (atl[ny][nx]) continue;
                    if (matrix[ny][nx] < d) continue;
                    que.emplace(ny, nx);
                    atl[ny][nx] = true;
                }
            }
        }
        vector<vector<int>> res;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (pac[i][j] && atl[i][j]) res.push_back({i, j});
        return res;
    }
};

int main(){
    return 0;
}
