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
    bool ans = false;
    rep(i, 10) rep(j, 10) {
        vs a2 = a;
        a2[i][j] = 'o';
        queue<pii> q;
        q.emplace(i, j);
        a2[i][j] = '.';
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p.first, x = p.second;
            const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i2, 4) {
                int ny = y + dy[i2], nx = x + dx[i2];
                if (ny<0||ny>=10||nx<0||nx>=10) continue;
                if (a2[ny][nx] != 'o') continue;
                q.emplace(ny, nx);
                a2[ny][nx] = '.';
            }
        }
        bool ok = true;
        rep(i2, 10) rep(j2, 10) {
            if (a2[i2][j2] == 'o') ok = false;
        }
        if (ok) ans = true;
    }
    if (ans) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}
