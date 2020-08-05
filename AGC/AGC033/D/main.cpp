#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];
    vector<vector<vector<vi>>> dpw(h, vector<vector<vi>>(h, vector<vi>(w, vi(17, -1)))), dph(w, vector<vector<vi>>(w, vector<vi>(h, vi(17, -1))));
    rep(i, h) {
        int l = 0, r = 0;
        while (r < w) {
            char t = a[i][l];
            while (a[i][r]==t) {
                ++r;
                if (r >= w) break;
            }
            for (int j=l; j<r; ++j) dpw[i][i][j][0] = r-1;
            l = r;
        }
    }
    rep(i, h) rep1(j, h-i-1) rep(k, w) {
        if (a[i][k] != a[i+j][k]) continue;
        dpw[i][i+j][k][0] = min(dpw[i][i+j-1][k][0], dpw[i+j][i+j][k][0]);
    }
    rep(i, w) {
        int l = 0, r = 0;
        while (r < h) {
            char t = a[l][i];
            while (a[r][i]==t) {
                ++r;
                if (r >= h) break;
            }
            for (int j=l; j<r; ++j) dph[i][i][j][0] = r-1;
            l = r;
        }
    }
    rep(i, w) rep1(j, w-i-1) rep(k, h) {
        if (a[k][i] != a[k][i+j]) continue;
        dph[i][i+j][k][0] = min(dph[i][i+j-1][k][0], dph[i+j][i+j][k][0]);
    }
    rep1(k, 16) {
        rep(i, h) for (int i2=i; i2<h; ++i2) {
            int r = 0;
            rep(j, w) {
                r = max(r, j);
                bool ok = (dpw[i][i2][j][k-1]!=-1), ok2 = false;
                if (ok) {
                    if (dpw[i][i2][j][k-1]==w-1) break;
                    r = dpw[i][i2][dpw[i][i2][j][k-1]+1][k-1];
                }
                while (r < w-1) {
                    if (ok) ++r;
                    if (dph[j][r][i][k-1]==-1) break;
                    if (dph[j][r][i][k-1]==h-1) {
                        ok2 = true;
                        ++r;
                        break;
                    }
                    int r2 = dph[j][r][dph[j][r][i][k-1]+1][k-1];
                    if (r2 == -1) break;
                    if (r2 < i2) break;
                    ++r; ok2 = true;
                }
                if (ok||ok2) {
                    --r;
                    dpw[i][i2][j][k] = r;
                }
            }
        }
        rep(i, w) for (int i2=i; i2<w; ++i2) {
            int r = 0;
            rep(j, h) {
                r = max(r, j);
                bool ok = (dph[i][i2][j][k-1]!=-1), ok2 = false;
                if (ok) {
                    if (dph[i][i2][j][k-1]==h-1) break;
                    r = dph[i][i2][dph[i][i2][j][k-1]+1][k-1];
                }
                while (r < h-1) {
                    if (ok) ++r;
                    if (dpw[j][r][i][k-1]==-1) break;
                    if (dpw[j][r][i][k-1]==h-1) {
                        ok2 = true;
                        ++r;
                        break;
                    }
                    int r2 = dpw[j][r][dpw[j][r][i][k-1]+1][k-1];
                    if (r2 == -1) break;
                    if (r2 < i2) break;
                    ++r; ok2 = true;
                }
                if (ok||ok2) {
                    --r;
                    dph[i][i2][j][k] = r;
                }
            }
        }
    }
    int ans = 1e9;
    rep(k, 17) {
        if (dpw[0][h-1][0][k]==w-1 || dph[0][w-1][0][k]==h-1) {
            ans = k;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
