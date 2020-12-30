#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        auto ans = board;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            int cnt = 0;
            for (int i2=-1; i2<=1; ++i2) for (int j2=-1; j2<=1; ++j2) {
                int y = i+i2, x = j+j2;
                if (y==i && j==x) continue;
                if (y<0 || y>=m || x<0 || x>=n) continue;
                if (board[y][x] == 1) ++cnt;
            }
            if (cnt<=1 || cnt>=4) ans[i][j] = 0;
            if (cnt == 3) ans[i][j] = 1;
        }
        board = ans;
    }
};

int main() {
    Solution cl;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m, vector<int>(n));
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) cin >> board[i][j];
    cl.gameOfLife(board);
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
        printf("%d%c", board[i][j], (j<n-1?' ':'\n'));
    }
    return 0;
}
