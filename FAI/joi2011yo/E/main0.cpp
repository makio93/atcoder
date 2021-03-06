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
    int h, w, n;
    cin >> h >> w >> n;
    vs m(h);
    rep(i, h) cin >> m[i];
    int ans = 0;
    const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
    rep1(k, n) {
        char f = (k==1)?'S':k-1+'0', t = k+'0';
        queue<pii> q;
        vector<vi> dist(h, vi(w, INF));
        rep(i, h) rep(j, w) {
            if (m[i][j]==f) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
        bool ok = false;
        while (!ok) {
            pii p = q.front(); q.pop();
            int y = p.first, x = p.second;
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0||ny>=h||nx<0||nx>=w) continue;
                if (m[ny][nx]=='X') continue;
                if (dist[ny][nx]!=INF) continue;
                if (m[ny][nx]==t) {
                    ans += dist[y][x] + 1;
                    ok = true;
                    break;
                }
                q.emplace(ny, nx);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
