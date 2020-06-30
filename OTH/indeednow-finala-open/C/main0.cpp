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

int main(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(n), c(n), w(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> w[i];
    vi x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    vector<vector<vi>> dp(101, vector<vi>(101, vi(101, -1)));
    dp[0][0][0] = 0;
    rep(i, n) dp[a[i]][b[i]][c[i]] = max(dp[a[i]][b[i]][c[i]], w[i]);
    rep(i, 101) rep(j, 101) rep(k, 101) {
        int mx = -1;
        rep(h, 1<<3) {
            int ni[] = { i, j, k };
            rep(h2, 3) if (h&(1<<h2) && ni[h2]>0) ni[h2]--;
            mx = max(mx, dp[ni[0]][ni[1]][ni[2]]);
        }
        dp[i][j][k] = mx;
    }
    rep(i, m) cout << dp[x[i]][y[i]][z[i]] << endl;
    return 0;
}
