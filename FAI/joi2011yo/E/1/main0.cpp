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
    vs s(h);
    rep(i, h) cin >> s[i];
    int ans = 0;
    rep(i0, n) {
        char b = '0' + i0, e = '0' + (i0 + 1);
        if (b == '0') b = 'S';
        vs s2 = s;
        queue<pii> q;
        vector<vi> d(h, vi(w, INF));
        auto ps = [&] (int i, int j, int b) {
            if (i<0||i>=h||j<0||j>=w) return;
            if (s2[i][j]=='X'||s2[i][j]==' ') return;
            q.push({i, j});
            s2[i][j] = ' ';
            d[i][j] = b;
        };
        int ib, jb, ie, je;
        rep(i, h) rep(j, w) {
            if (s2[i][j] == b) {
                ib = i; jb = j;
            }
            if (s2[i][j] == e) {
                ie = i; je = j;
            }
        }
        const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        ps(ib, jb, 0);
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            int y = p.first, x = p.second;
            int b = d[y][x] + 1;
            rep(i, 4) {
                int nx = x + dx[i], ny = y + dy[i];
                ps(ny, nx, b);
            }
        }
        ans += d[ie][je];
    }
    cout << ans << endl;
    return 0;
}
