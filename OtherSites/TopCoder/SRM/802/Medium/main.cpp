#include <bits/stdc++.h>
using namespace std;

class TheQuestForGold {
public:
    string explore(vector<string> cave) {
        int n = cave.size(), m = cave.front().length();
        vector<vector<bool>> safety(n, vector<bool>(m)), visited(n, vector<bool>(m));
        int syi = -1, sxi = -1;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (cave[i][j] == 'S') { syi = i; sxi = j; }
        queue<pair<int, int>> que;
        bool ans = false;
        que.emplace(syi, sxi);
        visited[syi][sxi] = true;
        while (!que.empty()) {
            auto pi = que.front(); que.pop();
            int yi = pi.first, xi = pi.second;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            safety[yi][xi] = true;
            bool slime = false;
            for (int i1=0; i1<4; ++i1) {
                int tyi = yi + dy[i1], txi = xi + dx[i1];
                if (tyi<0 || tyi>=n || txi<0 || txi>=m) continue;
                if (cave[tyi][txi] == 'P') slime = true;
            }
            if (!slime) {
                for (int i1=0; i1<4; ++i1) {
                    int tyi = yi + dy[i1], txi = xi + dx[i1];
                    if (tyi<0 || tyi>=n || txi<0 || txi>=m) continue;
                    safety[tyi][txi] = true;
                }
            }
            for (int i1=0; i1<4; ++i1) {
                int tyi = yi + dy[i1], txi = xi + dx[i1];
                if (tyi<0 || tyi>=n || txi<0 || txi>=m) continue;
                if (!safety[tyi][txi]) continue;
                if (visited[tyi][txi]) continue;
                if (cave[tyi][txi] == 'T') {
                    ans = true;
                    break;
                }
                que.emplace(tyi, txi);
                visited[tyi][txi] = true;
            }
            if (ans) break;
        }
        if (ans) return "gold";
        else return "no gold";
    }
};

int main(){
    return 0;
}
