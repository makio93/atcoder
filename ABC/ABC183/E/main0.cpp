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

//const long long mod = 1000000007;
using mint = modint1000000007;

int h, w;
vs s;
vector<vector<mint>> dp;
vector<vector<bool>> visited;
mint dfs(int i, int j) {
    if (visited[i][j]) return dp[i][j];
    if (i==h-1 && j==w-1) {
        visited[i][j] = true;
        dp[i][j] = mint(1);
        return mint(1);
    }
    if (s[i][j] == '#') {
        visited[i][j] = true;
        dp[i][j] = mint(0);
        return mint(0);
    }
    mint res = 0;
    for (int j2=j+1; j2<w; ++j2) {
        if (s[i][j2] == '#') break;
        if (visited[i][j2]) res += dp[i][j2];
        else res += dfs(i, j2);
    }
    for (int i2=i+1,j2=j+1; i2<h&&j2<w; ++i2,++j2) {
        if (s[i2][j2] == '#') break;
        if (visited[i2][j2]) res += dp[i2][j2];
        else res += dfs(i2, j2);
    }
    for (int i2=i+1; i2<h; ++i2) {
        if (s[i2][j] == '#') break;
        if (visited[i2][j]) res += dp[i2][j];
        else res += dfs(i2, j);
    }
    visited[i][j] = true;
    dp[i][j] = res;
    return res;
}

int main(){
    cin >> h >> w;
    s = vs(h);
    rep(i, h) cin >> s[i];
    dp = vector<vector<mint>>(h, vector<mint>(w, 0));
    visited = vector<vector<bool>>(h, vector<bool>(w, false));
    mint ans = dfs(0, 0);
    cout << ans.val() << endl;
    return 0;
}
