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
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w==0 && h==0) break;
        vs wall(2*h-1);
        cin.ignore();
        rep(i, sz(wall)) getline(cin, wall[i]);
        queue<pii> q;
        vector<vi> dist(h, vi(w, INF));
        q.emplace(0, 0);
        dist[0][0] = 1;
        while (!q.empty()) {
            pii p = q.front(); q.pop();
            int y = p.first, x = p.second;
            int d = dist[y][x];
            const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if (wall[y+ny][x+nx]=='1') continue;
                if (dist[ny][nx]!=INF) continue;
                q.emplace(ny, nx);
                dist[ny][nx] = d + 1;
            }
        }
        int ans = dist[h-1][w-1];
        if (ans==INF) ans = 0;
        cout << ans << endl;
    }
    return 0;
}
