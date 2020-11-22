#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];
    vector<set<pii>> tele(26);
    pii s, g;
    rep(i, h) rep(j, w) {
        if (a[i][j]=='#' || a[i][j]=='.') continue;
        if (a[i][j]=='S') s = {i, j};
        else if (a[i][j]=='G') g = {i, j};
        else tele[(int)(a[i][j]-'a')].emplace(i, j);
    }
    vector<vi> d(h, vi(w, INF));
    queue<pii> q;
    q.emplace(s);
    d[s.first][s.second] = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int py = p.first, px = p.second, pd = d[py][px], nd = pd+1;
        const vi dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};
        rep(i, 4) {
            int ny = py + dy[i], nx = px + dx[i];
            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if (a[ny][nx] == '#') continue;
            if (d[ny][nx] <= nd) continue;
            if (!(ny==g.first && nx==g.second)) q.emplace(ny, nx);
            d[ny][nx] = nd;
        }
        if (a[py][px]!='.' && islower((char)(a[py][px]))) {
            if (!tele[(int)(a[py][px]-'a')].empty()) {
                for (auto p2 : tele[(int)(a[py][px]-'a')]) {
                    int ny = p2.first, nx = p2.second;
                    if (ny==py && nx==px) continue;
                    if (d[ny][nx] <= nd) continue;
                    q.emplace(ny, nx);
                    d[ny][nx] = nd;
                }
                tele[(int)(a[py][px]-'a')].clear();
            }
        }
    }
    if (d[g.first][g.second] != INF) cout << d[g.first][g.second] << endl;
    else cout << -1 << endl;
    return 0;
}
