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

const string YES = "YES";
const string NO = "NO";

typedef struct point {
    int i, j;
} P;

int main(){
    int h, w;
    cin >> h >> w;
    vs c(h);
    rep(i, h) cin >> c[i];
    queue<pair<P, int>> q;
    vector<vi> dist(h, vi(w, -1));
    auto ps = [&] (int i, int j, int b, int d) {
        if (i<0||i>=h||j<0||j>=w) return;
        if (c[i][j] == ' ') return;
        if (c[i][j] == '#') {
            if (b == 0) return;
            else --b;
        }
        c[i][j] = ' ';
        q.push({{i, j}, b});
        dist[i][j] = d;
    };
    P s, g;
    rep(i, h) rep(j, w) {
        if (c[i][j] == 's') {
            s.i = i; s.j = j;
        }
        if (c[i][j] == 'g') {
            g.i = i; g.j = j;
        }
    }
    const int di[] = { -1, 1, 0, 0 }, dj[] = { 0, 0, -1, 1 };
    ps(s.i, s.j, 2, 0);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int i = p.first.i, j = p.first.j;
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            ps(ni, nj, p.second, dist[i][j]+1);
        }
    }
    int ans = dist[g.i][g.j];
    cout << (ans!=-1?YES:NO) << endl;
    return 0;
}
