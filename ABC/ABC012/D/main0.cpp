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
    int n, m;
    cin >> n >> m;
    vector<vpii> g(n);
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        --a; --b;
        g[a].emplace_back(b, t);
        g[b].emplace_back(a, t);
    }
    vector<vi> dp(n, vi(n, INF));
    rep(i, n) dp[i][i] = 0;
    rep(i, n) for (auto t : g[i]) dp[i][t.first] = t.second;
    rep(k, n) rep(i, n) rep(j, n) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
    int ans = INF;
    rep(i, n) {
        int mx = 0;
        rep(j, n) mx = max(mx, dp[i][j]);
        ans = min(ans, mx);
    }
    cout << ans << endl;
    return 0;
}
