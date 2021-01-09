#include <bits/stdc++.h>
using namespace std;

class FlightPlan {
public:
    long long fly(int R, int C, vector<int> H, int cup, int cdn, int clr) {
        vector<vector<map<int, long long>>> dist(R, vector<map<int, long long>>(C));
        vector<vector<map<int, bool>>> visited(R, vector<map<int, bool>>(C));
        priority_queue<pair<long long, tuple<int, int, int>>, vector<pair<long long, tuple<int, int, int>>>, greater<pair<long long, tuple<int, int, int>>>> que;
        que.emplace(0, make_tuple(0, 0, H[0*C+0]));
        dist[0][0][H[0*C+0]] = 0;
        visited[0][0][H[0*C+0]] = true;
        while (!que.empty()) {
            auto elem = que.top(); que.pop();
            int y = get<0>(elem.second), x = get<1>(elem.second), h = get<2>(elem.second);
            long long d = elem.first;
            if (dist[y][x][h] != d) continue;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i1=0; i1<4; ++i1) {
                int ny = y + dy[i1], nx = x + dx[i1];
                if (ny<0 || ny>=R || nx<0 || nx>=C) continue;
                int dh = max(0, H[ny*C+nx]-h), nh = h + dh, nd = d + clr + dh * cup;
                if (visited[ny][nx][nh] && dist[ny][nx][nh]<=nd) continue;
                que.emplace(nd, make_tuple(ny, nx, nh));
                dist[ny][nx][nh] = nd;
                if (!visited[ny][nx][nh]) visited[ny][nx][nh] = true;
            }
        }
        long long ans = (long long)(1e18);
        for (auto p : dist[R-1][C-1]) {
            long long val = p.second + cdn * (p.first - H[(R-1)*C+(C-1)]);
            ans = min(ans, val);
        }
        return ans;
    }
};
