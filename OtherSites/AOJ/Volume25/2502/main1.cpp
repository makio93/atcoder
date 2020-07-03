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
    int n;
    cin >> n;
    vi s(n), l(n), p(n);
    rep(i, n) cin >> s[i] >> l[i] >> p[i];
    int m;
    cin >> m;
    vi w(m);
    rep(i, m) cin >> w[i];
    int wsize = 0;
    rep(i, m) wsize = max(wsize, w[i]);
    vector<vi> dp(n+1, vi(wsize+1));
    rep(i, n) rep(j, wsize+1) {
        dp[i+1][j] = dp[i][j];
        if (j-s[i]>=0) {
            for (int k=s[i]; k<=l[i]&&j-k>=0; ++k) {
                dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-k]+p[i]);
            }
        }
    }
    bool ok = true;
    vi ans(m);
    rep(i, m) {
        if (dp[n][w[i]] == 0) ok = false;
        else ans[i] = dp[n][w[i]];
    }
    if (ok) rep(i, m) cout << ans[i] << endl;
    else cout << -1 << endl;
    return 0;
}
