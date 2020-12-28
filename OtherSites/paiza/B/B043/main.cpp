#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, h0, w0;
    cin >> h >> w >> h0 >> w0;
    --h0; --w0;
    pair<int, int> p = { h0, w0 };
    vector<string> s(h);
    for (int i=0; i<h; ++i) cin >> s[i];
    const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
    int dir = 0;
    while (p.first>=0 && p.first<h && p.second>=0 && p.second<w) {
        if (s[p.first][p.second] == '.') {
            s[p.first][p.second] = '*';
            dir = (dir + 1) % 4;
        }
        else {
            s[p.first][p.second] = '.';
            dir = ((dir + 4) - 1) % 4;
        }
        int ny = p.first + dy[dir], nx = p.second + dx[dir];
        p = { ny, nx };
    }
    for (int i=0; i<h; ++i) cout << s[i] << endl;
    return 0;
}
