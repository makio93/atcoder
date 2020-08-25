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
    int a, b;
    cin >> a >> b;
    vi ai(a), bi(b);
    rep(i, a) cin >> ai[i];
    rep(i, b) cin >> bi[i];
    vector<vector<vi>> dp(a+1, vector<vi>(b+1, vi(2)));
    rep(i, a+1) rep(j, b+1) {
        if (i==0 && j==0) continue;
        int t = (i+j) % 2;
        bool isa = (j==0);
        if (i>0&&j>0) isa = (dp[i-1][j][t]+ai[i-1] > dp[i][j-1][t]+bi[j-1]);
        if (isa) {
            dp[i][j][t] = max(dp[i][j][t], dp[i-1][j][t]+ai[i-1]);
            dp[i][j][1-t] = max(dp[i][j][1-t], dp[i-1][j][1-t]);
        }
        if (!isa) {
            dp[i][j][t] = max(dp[i][j][t], dp[i][j-1][t]+bi[j-1]);
            dp[i][j][1-t] = max(dp[i][j][1-t], dp[i][j-1][1-t]);
        }
    }
    cout << dp[a][b][1] << endl;
    return 0;
}
