#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 100000;

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<vi>> dp(2, vector<vi>(m+1, vi(s+1)));
    dp[0][0][0] = 1;
    rep(i, n*n+1) {
        int to = (i+1)%2, fr = i%2;
        if (i>0) rep(j, m) rep(k, s) {
            dp[fr][j+1][k+1] = (dp[fr][j+1][k+1] + dp[fr][j][k]) % MOD;
        }
        if (i==n*n) break;
        rep(j, m) rep(k, s) {
            if (k+j+1<=s) dp[to][j+1][k+j+1] = (dp[to][j+1][k+j+1] + dp[fr][j][k]) % MOD;
        }
        dp[fr] = vector<vi>(m+1, vi(s+1));
    }
    int ans = 0;
    rep(i, m+1) ans = (ans + dp[n*n%2][i][s]) % MOD;
    rep(i, m+1) ans = (ans - dp[(n*n-1)%2][i][s] + MOD) % MOD;
    cout << ans << endl;
    return 0;
}
