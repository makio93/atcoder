#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int h = isWater.size(), w = isWater.front().size();
        vector<vector<int>> height(h, vector<int>(w, (int)(1e9)));
        queue<int> que;
        for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
            if (isWater[i][j] != 1) continue;
            que.push(i*w+j);
            height[i][j] = 0;
        }
        while (!que.empty()) {
            int p = que.front(); que.pop();
            int y = p / w, x = p % w, d = height[y][x], nd = d + 1;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0||ny>=h||nx<0||nx>=w) continue;
                if (height[ny][nx] <= nd) continue;
                que.push(ny*w+nx);
                height[ny][nx] = nd;
            }
        }
        return height;
    }
};

int main(){
    return 0;
}
