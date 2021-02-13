#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.front().size();
        vector<vector<int>> dist(n, vector<int>(m, (int)(1e9)));
        queue<pair<int, int>> que;
        if (grid[0][0] == 0) que.emplace(0, 0);
        dist[0][0] = 1;
        while (!que.empty()) {
            auto p = que.front(); que.pop();
            int vy = p.first, vx = p.second, d = dist[vy][vx], nd = d + 1;
            const vector<int> dy = { -1, 0, 1 }, dx = { -1, 0, 1 };
            for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
                int ny = vy + dy[i], nx = vx + dx[j];
                if (ny==vy && nx==vx) continue;
                if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if (grid[ny][nx] == 1) continue;
                if (dist[ny][nx] <= nd) continue;
                que.emplace(ny, nx);
                dist[ny][nx] = nd;
            }
        }
        if (dist[n-1][m-1] == (int)(1e9)) return -1;
        else return dist[n-1][m-1];
    }
};

int main(){
    return 0;
}
