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
    int r, c, k;
    cin >> r >> c >> k;
    vector<vi> vmp(r, vi(c));
    rep(i, k) {
        int ri, ci, v;
        cin >> ri >> ci >> v;
        --ri; --ci;
        vmp[ri][ci] = v;
    }
    vector<vector<vll>> dp(r+1, vector<vll>(c+1, vll(4)));
    rep(i, c+1) rep(j, 4) dp[0][i][j] = 0;
    rep(i, r+1) rep(j, 4) dp[i][0][j] = 0;
    rep(i, r+1) rep(j, c+1) dp[i][j][0] = 0;
    vector<vll> vals(r+1, vll(c+1));
    rep1(i, r) rep1(j, c) {
        rep1(t, 3) {
            if (vmp[i-1][j-1] == 0) dp[i][j][t] = max(vals[i-1][j], dp[i][j-1][t]);
            else {
                ll val1 = max(vals[i-1][j]+vmp[i-1][j-1], dp[i][j-1][t-1]+vmp[i-1][j-1]);
                ll val2 = max(vals[i-1][j], dp[i][j-1][t]);
                dp[i][j][t] = max(val1, val2);
            }
        }
        rep(t, 4) vals[i][j] = max(vals[i][j], dp[i][j][t]);
    }
    ll ans = 0;
    rep(i, 4) ans = max(ans, dp[r][c][i]);
    cout << ans << endl;
    return 0;
}