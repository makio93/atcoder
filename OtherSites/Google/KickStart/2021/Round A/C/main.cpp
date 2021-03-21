#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int t;
    cin >> t;
    rep2(i1, 1, t) {
        int r, c;
        cin >> r >> c;
        v(v(ll)) g(r, v(ll)(c));
        rep(i, r) rep(j, c) cin >> g[i][j];
        priority_queue<p2(ll,p(int))> unvisited;
        rep(i, r) rep(j, c) unvisited.emplace(g[i][j], p(int){i,j});
        auto g2 = g;
        v(v(bool)) visited(r, v(bool)(c));
        while (!unvisited.empty()) {
            p2(ll,p(int)) start;
            do {
                start = unvisited.top(); unvisited.pop();
            } while (visited[start.second.first][start.second.second] && !unvisited.empty());
            if (unvisited.empty() && visited[start.second.first][start.second.second]) break;
            int sy = start.second.first, sx = start.second.second;
            queue<p(int)> que;
            que.emplace(sy,sx);
            visited[sy][sx] = true;
            while (!que.empty()) {
                auto pos = que.front(); que.pop();
                int y = pos.first, x = pos.second;
                ll d = g2[y][x], nd = d-1;
                const v(int) dy = {-1,0,1,0}, dx = {0,1,0,-1};
                rep(i2, 4) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=r || nx<0 || nx>=c) continue;
                    if (g2[ny][nx] > d) continue;
                    if (visited[ny][nx] && g2[ny][nx]>=nd) continue;
                    que.emplace(ny,nx);
                    g2[ny][nx] = max(g2[ny][nx], nd);
                    visited[ny][nx] = true;
                }
            }
        }
        ll cnt = 0;
        rep(i, r) rep(j, c) cnt += max(0LL, g2[i][j]-g[i][j]);
        cout << "Case #" << i1 << ": " << cnt << endl;
    }
    return 0;
}
