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

vector<vi> b, c;

int score(int i, int j, vector<vi> a) {
    int res = 0;
    if (i<=1) if (a[i+1][j]!=-1&&a[i][j]==a[i+1][j]) res += b[i][j];
    if (i>0) if (a[i-1][j]!=-1&&a[i][j]==a[i-1][j]) res += b[i-1][j];
    if (j<=1) if (a[i][j+1]!=-1&&a[i][j]==a[i][j+1]) res += c[i][j];
    if (j>0) if (a[i][j-1]!=-1&&a[i][j]==a[i][j-1]) res += c[i][j-1];
    return res;
}

vector<vector<vector<map<vector<vi>, int>>>> dp;
int calc(int i, int j, int d, vector<vi> a) {
    if (!dp[i][j][d].empty() && dp[i][j][d].count(a)!=0) return dp[i][j][d][a];
    vector<vi> a2 = a;
    a2[i][j] = d%2;
    if (d%2==1) {
        int res = 0;
        rep(i2, 3) rep(j2, 3) {
            if (a2[i2][j2] != -1) continue;
            res = max(res, calc(i2, j2, d+1, a2));
        }
        res += score(i, j, a2);
        return (dp[i][j][d][a] = res);
    }
    else {
        int res = INF;
        rep(i2, 3) rep(j2, 3) {
            if (a2[i2][j2] != -1) continue;
            res = min(res, calc(i2, j2, d+1, a2));
        }
        if (res == INF) res = 0;
        res += score(i, j, a2);
        return (dp[i][j][d][a] = res);
    }
}

int main(){
    b = vector<vi>(3, vi(3)); c = vector<vi>(3, vi(3));
    rep(i, 2) rep(j, 3) cin >> b[i][j];
    rep(i, 3) rep(j, 2) cin >> c[i][j];
    dp = vector<vector<vector<map<vector<vi>, int>>>>(3, vector<vector<map<vector<vi>, int>>>(3, vector<map<vector<vi>, int>>(9)));
    vector<vi> tp(3, vi(3, -1));
    int ans = 0;
    rep(i, 3) rep(j, 3) ans = max(ans, calc(i, j, 0, tp));
    int sum = 0;
    rep(i, 2) rep(j, 3) sum += b[i][j];
    rep(i, 3) rep(j, 2) sum += c[i][j];
    cout << ans << endl;
    cout << (sum - ans) << endl;
    return 0;
}
