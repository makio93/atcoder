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

#define INF (1e15)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int v, e;
    cin >> v >> e;
    vector<vpii> g(v);
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    vector<vll> dp(v, vll(v, INF));
    rep(i, v) dp[i][i] = 0;
    rep(i, v) for (auto p : g[i]) dp[i][p.first] = p.second;
    rep1(k, v) rep(i, v) rep(j, v) {
        if (dp[i][k-1]==INF || dp[k-1][j]==INF) continue;
        dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k-1][j]);
    }
    bool neg = false;
    rep(i, v) if (dp[i][i] < 0) neg = true;
    if (neg) cout << "NEGATIVE CYCLE" << endl;
    else {
        rep(i, v) rep(j, v) {
            if (dp[i][j] != INF) printf("%lld", dp[i][j]);
            else cout << "INF";
            cout << (j<v-1?' ':'\n');
        }
    }
    return 0;
}
