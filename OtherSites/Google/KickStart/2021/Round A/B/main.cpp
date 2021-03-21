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
        v(v(int)) grid(r, v(int)(c));
        rep(i, r) rep(j, c) cin >> grid[i][j];
        v(v(v(int))) len(4, v(v(int))(r+2, v(int)(c+2)));
        const v(v(int)) dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
        rep(i2, 4) {
            if (i2/2==0) {
                rep2(i, 1, r) {
                    int y = i, x = (i2%2==0) ? 1 : c;
                    int py = y - dir[i2][0], px = x - dir[i2][1];
                    rep2(j, 1, c) {
                        if (grid[y-1][x-1] == 1) len[i2][y][x] = len[i2][py][px] + 1;
                        else len[i2][y][x] = 0;
                        py = y; px = x;
                        y += dir[i2][0]; x += dir[i2][1];
                    }
                }
            }
            else {
                rep2(i, 1, c) {
                    int y = (i2%2==0) ? 1 : r, x = i;
                    int py = y - dir[i2][0], px = x - dir[i2][1];
                    rep2(j, 1, r) {
                        if (grid[y-1][x-1] == 1) len[i2][y][x] = len[i2][py][px] + 1;
                        else len[i2][y][x] = 0;
                        py = y; px = x;
                        y += dir[i2][0]; x += dir[i2][1];
                    }
                }
            }
        }
        int cnt = 0;
        rep(i2, 4) {
            v(int) tdir;
            if (i2/2 == 0) tdir = { 2, 3 };
            else tdir = { 0, 1 };
            rep2(i, 1, r) rep2(j, 1, c) {
                if (len[i2][i][j] / 2 >= 2){
                    rep(j2, 2) {
                        if (len[tdir[j2]][i][j] >= 2) cnt += min(len[i2][i][j]/2, len[tdir[j2]][i][j]) - 1;
                    }
                }
            }
        }
        cout << "Case #" << i1 << ": " << cnt << endl;
    }
    return 0;
}
