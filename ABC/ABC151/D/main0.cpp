#include <bits/stdc++.h>
using namespace std;

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
    vs s(h);
    rep(i, h) cin >> s[i];
    int ans = 0;
    rep(i, h) rep(j, w) {
        queue<pii> q;
        vector<vi> dist(h, vi(w, INF));
        if (s[i][j] == '#') continue;
        q.emplace(i, j);
        dist[i][j] = 0;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p.first, x = p.second, d = dist[y][x];
            const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i2, 4) {
                int ny = y + dy[i2], nx = x + dx[i2], nd = d + 1;
                if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if (s[ny][nx] == '#') continue;
                if (dist[ny][nx] <= nd) continue;
                q.emplace(ny, nx);
                dist[ny][nx] = nd;
            }
        }
        rep(i2, h) rep(j2, w) {
            if (dist[i2][j2] == INF) continue;
            ans = max(ans, dist[i2][j2]);
        }
    }
    cout << ans << endl;
    return 0;
}
