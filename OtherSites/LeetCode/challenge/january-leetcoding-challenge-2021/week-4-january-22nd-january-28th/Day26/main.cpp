#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights.front().size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        vector<int> dist(n*m, (int)(1e9));
        que.emplace(0, 0);
        dist[0] = 0;
        while (!que.empty()) {
            auto pi = que.top(); que.pop();
            int diff = pi.first, place = pi.second, y = place / m, x = place % m;
            if (dist[place] != diff) continue;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i2=0; i2<4; ++i2) {
                int ny = y + dy[i2], nx = x + dx[i2];
                if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                int nplace = ny * m + nx, ndiff = max(diff, abs(heights[ny][nx]-heights[y][x]));
                if (dist[nplace] <= ndiff) continue;
                que.emplace(ndiff, nplace);
                dist[nplace] = ndiff;
            }
        }
        return dist[n*m-1];
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> heights(n, vector<int>(m));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) cin >> heights[i][j];
    cout << cl.minimumEffortPath(heights) << endl;
    return 0;
}
