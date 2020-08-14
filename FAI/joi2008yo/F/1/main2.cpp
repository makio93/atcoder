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
    int n, k;
    cin >> n >> k;
    vector<vi> cost(n, vi(n, INF));
    rep(i, n) cost[i][i] = 0;
    vector<vi> dp = cost;
    rep(i, k) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            int ans = dp[a][b];
            if (ans == INF) cout << -1 << endl;
            else cout << ans << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            if (e >= cost[c][d]) continue;
            cost[c][d] = cost[d][c] = e;
            dp = cost;
            rep(h, n) rep(j1, n) rep(j2, n) {
                dp[j1][j2] = min(dp[j1][j2], dp[j1][h]+dp[h][j2]);
            }
        }
    }
    return 0;
}
