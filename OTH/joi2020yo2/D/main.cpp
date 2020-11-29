#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

//const int CNT = 1e6+5;

int main(){
    int m, r;
    cin >> m >> r;
    vector<vi> keys(4, vi(3));
    rep1(i, 3) rep(j, 3) {
        keys[i][j] = (i-1)*3+1+j;
    }
    keys[0] = { 0, -1, -1 };
    vector<vi> cost(10, vi(10, 0));
    rep(i1, 4) rep(j1, 3) {
        int snum = keys[i1][j1];
        if (snum == -1) continue;
        queue<pii> q;
        vector<vi> dist(4, vi(3, INF));
        q.emplace(i1, j1);
        dist[i1][j1] = 1;
        cost[snum][keys[i1][j1]] = 1;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p.first, x = p.second, d = dist[y][x];
            int nd = d + 1;
            const vi dy = { 1, 0, -1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=4 || nx<0 || nx>=3) continue;
                if (keys[ny][nx] == -1) continue;
                if (dist[ny][nx] <= nd) continue;
                q.emplace(ny, nx);
                dist[ny][nx] = nd;
                cost[snum][keys[ny][nx]] = nd;
            }
        }
    }
    ll val = r;
    int ans = INF;
    rep(i, m*10) {
        int sum = 0;
        ll tmp = val;
        int to = (int)(tmp % 10LL);
        tmp /= 10LL;
        while (tmp > 0LL) {
            int from = (int)(tmp % 10LL);
            sum += cost[from][to];
            to = from;
            tmp /= 10LL;
        }
        sum += cost[0][to];
        ans = min(ans, sum);
        val += (ll)(m);
    }
    cout << ans << endl;
    return 0;
}
