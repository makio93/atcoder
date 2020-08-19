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
    vector<vector<vi>> dp(3, vector<vi>(m+2, vi(s+m+2)));
    dp[0][1][1] = 1;
    rep(i, n*n+1) {
        int fr = i % 2, to = (i+1) % 2;
        rep1(j, m) rep1(k, s+m) {
            dp[fr][j+1][k+1] = (dp[fr][j+1][k+1] + dp[fr][j][k]) % MOD;
        }
        if (i == n*n) break;
        rep1(j, m) rep1(k, s+m) {
            if (k+j+1<=s+m+1) dp[to][j+1][k+j+1] = (dp[to][j+1][k+j+1] + dp[fr][j][k]) % MOD;
        }
        
        dp[fr] = vector<vi>(m+2, vi(s+m+2));
    }
    //if (m < 10) rep(i, 2) rep(j, m+2) rep(k, s+m+2) printf("%lld%c", dp[i][j][k], (k<s+m+1?' ':'\n'));
    cout << dp[n*n%2][m+1][s+m+1] << endl;
    return 0;
}
