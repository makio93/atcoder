#include <bits/stdc++.h>
using namespace std;

// UnionFind
struct UnionFind {
    vector<int> par;
    UnionFind(int n=0) {
        par = vector<int>(n, -1);
    }
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -par[find(x)];}
};

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> s(h, vector<int>(w));
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) cin >> s[i][j];
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int, pair<int, int>>> heights;
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) heights.emplace_back(s[i][j], pair<int, int>(i, j));
    sort(heights.rbegin(), heights.rend());
    pair<int, int> res = { (int)(1e9)+5, 1 };
    UnionFind uf(h*w);
    int gnum = 0;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    for (int i=0; i<h*w; ++i) {
        int y = heights[i].second.first, x = heights[i].second.second;
        visited[y][x] = true;
        vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        ++gnum;
        for (int i2=0; i2<4; ++i2){
            int ny = y + dy[i2], nx = x + dx[i2];
            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if (visited[ny][nx]) {
                bool resb = uf.unite(w*y+x, w*ny+nx);
                if (resb) --gnum;
            }
        }
        if (i+1<h*w && heights[i+1].first==heights[i].first) continue;
        if (gnum == n) res = min(res, { heights[i].first, -i });
    }
    int id = -(res.second);
    int ans = heights[id+1].first;
    cout << ans << endl;
    return 0;
}
