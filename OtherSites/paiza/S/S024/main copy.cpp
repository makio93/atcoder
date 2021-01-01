#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> s(h, vector<int>(w));
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) cin >> s[i][j];
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int mval = 0;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) mval = max(mval, s[i][j]);
    long long l = 0, r = mval+1;
    while (r-l > 1) {
        long long c = (l+r)/2;
        int cnt = 0;
        vector<vector<int>> board(h, vector<int>(w, 0));
        for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) if ((s[i][j]) <= (int)c) board[i][j] = -1;
        for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
            if (board[i][j] == -1) continue;
            if (board[i][j] == 1) continue;
            queue<pair<int, int>> q;
            q.emplace(i, j);
            board[i][j] = 1;
            while (!q.empty()) {
                auto p = q.front(); q.pop();
                int y = p.first, x = p.second;
                const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if (board[ny][nx] == -1) continue;
                    if (board[ny][nx] == 1) continue;
                    q.emplace(ny, nx);
                    board[ny][nx] = 1;
                }
            }
            ++cnt;
        }
        if (cnt < n) l = c+1;
        else if (cnt > n) r = c;
        else r = c+1;
    }
    cout << l << endl;
    return 0;
}
