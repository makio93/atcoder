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
    vs s(h);
    rep(i, h) cin >> s[i];
    int white = 0;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') ++white;
    }
    vector<vi> d(h, vi(w, INF));
    queue<pii> q;
    auto ps = [&] (int i, int j, int dist) {
        if (i<0||i>=h||j<0||j>=w) return;
        if (s[i][j] != '.') return;
        q.push({i, j});
        d[i][j] = dist;
        s[i][j] = ' ';
    };
    const int di[] = { -1, 1, 0, 0 }, dj[] = { 0, 0, -1, 1 };
    ps(0, 0, 0);
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second, dist = d[i][j];
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            ps(ni, nj, dist + 1);
        }
    }
    int res = d[h-1][w-1];
    int ans = (res!=INF)?(white-res-1):-1;
    cout << ans << endl;
    return 0;
}
