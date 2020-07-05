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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vll s(n+1);
    rep(i, n) s[i+1] = s[i] + a[i];
    vector<vll> dp(n+1, vll(n+1, INF));
    dp[0][0] = 0;
    rep(i, n) rep(j, n+1) {
        if (j > i+1) break;
        if (j==0) dp[i+1][j] = dp[i][j];
        else {
            ll prev = (i==0?0:(dp[i][j-1] + s[i]) / s[i]);
            ll now = max(prev * s[i+1] - s[i+1] + 1, 1LL);
            if (now > s[i+1]) now = INF;
            dp[i+1][j] = min(dp[i][j], now);
        }
    }
    int ans = -1;
    rep(i, n+1) if (dp[n][i] <= k) ans = i;
    cout << ans << endl;
    return 0;
}
