#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// 解説ページでの解法　３方向からの特殊な累積和を計算しながら高速化

//const long long mod = 1000000007;
using mint = modint1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];
    vector<vector<mint>> dp(h, vector<mint>(w));
    vector<vector<mint>> x(h, vector<mint>(w+1));
    vector<vector<mint>> y(h+1, vector<mint>(w));
    vector<vector<mint>> z(h+1, vector<mint>(w+1));
    dp[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') continue;
        if (j-1>=0) x[i][j] += x[i][j-1] + dp[i][j-1];
        if (i-1>=0) y[i][j] += y[i-1][j] + dp[i-1][j];
        if (i-1>=0 && j-1>=0) z[i][j] += z[i-1][j-1] + dp[i-1][j-1];
        dp[i][j] += x[i][j] + y[i][j] + z[i][j];
    }
    cout << dp[h-1][w-1].val() << endl;
    return 0;
}
