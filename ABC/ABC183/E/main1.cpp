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

// 解説放送による解法　上空にいる場合のテーブルを用いる

//const long long mod = 1000000007;
using mint = modint1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, h) cin >> s[i];
    vector<vector<mint>> dp(h, vector<mint>(w));
    vector<vector<mint>> dpx(h, vector<mint>(w));
    vector<vector<mint>> dpy(h, vector<mint>(w));
    vector<vector<mint>> dpxy(h, vector<mint>(w));
    dp[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') continue;
        if (j-1>=0) dpx[i][j] += dpx[i][j-1];
        if (i-1>=0) dpy[i][j] += dpy[i-1][j];
        if (i-1>=0 && j-1>=0) dpxy[i][j] += dpxy[i-1][j-1];
        dp[i][j] += dpx[i][j] + dpy[i][j] + dpxy[i][j];
        dpx[i][j] += dp[i][j];
        dpy[i][j] += dp[i][j];
        dpxy[i][j] += dp[i][j];
    }
    cout << dp[h-1][w-1].val() << endl;
    return 0;
}
