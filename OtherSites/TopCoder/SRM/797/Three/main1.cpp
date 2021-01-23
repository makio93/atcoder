#include <bits/stdc++.h>
using namespace std;

class FlightPlan {
public:
     long long fly(int R, int C, vector<int> H, int cup, int cdn, int clr) {
         vector<vector<vector<int>>> dist(R*C, vector<vector<int>>(R, vector<int>(C, (int)(1e9))));
         for (int i1=0; i1<R*C; ++i1) {
             if (H[0] > H[i1]) continue;
             queue<pair<int,int>> que;
             que.emplace(0, 0);
             dist[i1][0][0] = 0;
             while (!que.empty()) {
                 auto p = que.front(); que.pop();
                 int r = p.first, c = p.second, d = dist[i1][r][c], nd = d + 1;
                 const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
                 for (int i=0; i<4; ++i) {
                     int nr = r + dr[i], nc = c + dc[i];
                     if (nr<0 || nr>=R || nc<0 || nc>=C) continue;
                     if (H[nr*C+nc] > H[i1]) continue;
                     if (dist[i1][nr][nc] <= nd) continue;
                     que.emplace(nr, nc);
                     dist[i1][nr][nc] = nd;
                 }
             }
         }
         long long ans = (long long)(1e18);
         for (int i=0; i<R*C; ++i) {
             if (dist[i][R-1][C-1] == (int)(1e9)) continue;
             ans = min(ans, dist[i][R-1][C-1]*(long long)(clr)+(H[i]-H[0])*(long long)(cup)+(H[i]-H[R*C-1])*(long long)(cdn));
         }
         return ans;
     }
};

int main(){
    FlightPlan cl;
    int r, c, cup, cdn, clr;
    cin >> r >> c;
    vector<int> h(r*c);
    for (int i=0; i<r*c; ++i) cin >> h[i];
    cin >> cup >> cdn >> clr;
    cout << cl.fly(r, c, h, cup, cdn, clr) << endl;
    return 0;
}
