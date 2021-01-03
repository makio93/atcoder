#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, h;
    cin >> w >> h;
    vector<string> s(h);
    for (int i=0; i<h; ++i) cin >> s[i];
    vector<pair<int, int>> player(2, { -1, -1 });
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
        if (s[i][j] == '1') {
            player[0] = { i, j };
            s[i][j] = '.';
        }
        if (s[i][j] == '2') {
            player[1] = { i, j };
            s[i][j] = '.';
        }
    }
    vector<vector<int>> dist1(h, vector<int>(w, (int)(1e9))), dist2(h, vector<int>(w, (int)(1e9)));
    queue<pair<int, int>> q;
    q.emplace(player[0]);
    dist1[player[0].first][player[0].second] = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first, x = p.second, d = dist1[y][x], nd = d + 1;
        const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        for (int i1=0; i1<4; ++i1) {
            int ny = y + dy[i1], nx = x + dx[i1];
            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist1[ny][nx] <= nd) continue;
            q.emplace(ny, nx);
            dist1[ny][nx] = nd;
        }
    }
    dist2[player[1].first][player[1].second] = 1;
    if (dist1[player[1].first][player[1].second] > 1) q.emplace(player[1]);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first, x = p.second, d = dist2[y][x], nd = d + 1;
        const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        for (int i1=0; i1<4; ++i1) {
            int ny = y + dy[i1], nx = x + dx[i1];
            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist2[ny][nx] <= nd) continue;
            if (dist1[ny][nx] > nd) q.emplace(ny, nx);
            if (dist1[ny][nx] >= nd) dist2[ny][nx] = nd;
        }
    }
    int ans = 0;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
        if (dist1[i][j]==(int)(1e9) || dist2[i][j]==(int)(1e9)) continue;
        ans = max(ans, max(dist1[i][j], dist2[i][j]));
    }
    cout << ans << endl;
    return 0;
}
