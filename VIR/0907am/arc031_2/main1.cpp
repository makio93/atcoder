#include <bits/stdc++.h>
using namespace std;

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

const string YES = "YES";
const string NO = "NO";

int main(){
    vs a(10);
    rep(i, 10) cin >> a[i];
    vector<vector<bool>> board(10, vector<bool>(10));
    rep(i, 10) rep(j, 10) if (a[i][j] == 'o') board[i][j] = true;
    int cnt = 0;
    rep(i, 10) rep(j, 10) if (board[i][j]) ++cnt;
    auto check = [&] (int y, int x) {
        auto ok = [&] (int yi, int xi) { return (yi>=0&&yi<10&&xi>=0&&xi<10); };
        vector<vector<bool>> visited(10, vector<bool>(10));
        if (board[y][x]) return false;
        int sum = 0;
        queue<pii> q;
        q.emplace(y, x);
        visited[y][x] = true;
        const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int vy = p.first, vx = p.second;
            rep(i, 4) {
                int ny = vy + dy[i], nx = vx + dx[i];
                if (!ok(ny, nx)) continue;
                if (!board[ny][nx]) continue;
                if (visited[ny][nx]) continue;
                q.emplace(ny, nx);
                visited[ny][nx] = true;
                ++sum;
            }
        }
        return (sum == cnt);
    };
    rep(i, 10) rep(j, 10) {
        if (check(i, j)) {
            cout << YES << endl;
            return 0;
        }
    }
    cout << NO << endl;
    return 0;
}
