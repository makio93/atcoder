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

struct P {
    int y, x;
    P(int y, int x) : y(y), x(x) {}
};

const int ex = 250;
const vi dy = { 1, 1, 1, 0, 0, -1 }, dx = { 1, 0, -1, 1, -1, 0 };

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    vs board(501, string(501, '.'));
    rep(i, n) {
        int py, px;
        cin >> px >> py;
        board[ex+py][ex+px] = '#';
    }
    queue<P> q;
    vector<vi> dist(501, vi(501, INF));
    auto ps = [&] (int ny, int nx, int d) {
        if (ny>250||ny<-250||nx>250||nx<-250) return;
        if (board[ex+ny][ex+nx]=='#') return;
        if (dist[ex+ny][ex+nx]!=INF) return;
        q.push(P(ny, nx));
        dist[ex+ny][ex+nx] = d;
    };
    ps(0, 0, 0);
    while (!q.empty()) {
        P p = q.front(); q.pop();
        int pd = dist[ex+p.y][ex+p.x];
        rep(i, 6) {
            int ny = p.y + dy[i], nx = p.x + dx[i];
            ps(ny, nx, pd+1);
        }
    }
    int ans = dist[ex+y][ex+x];
    if (ans==INF) ans = -1;
    cout << ans << endl;
    return 0;
}
