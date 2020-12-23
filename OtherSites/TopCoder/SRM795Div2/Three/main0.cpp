#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// 過去問練習、自力ACできなかった

vector<vector<vll>> dp;
vector<vector<map<int, ll>>> memo;
ll calc(int u, int v, int val) {
    if (memo[u][v].find(val) != memo[u][v].end()) return memo[u][v][val];
    if (__builtin_popcount(val) == 0) return (memo[u][v][val] = 0);
    else if (__builtin_popcount(val) == 1) {
        int k = 0;
        while (val > 0) {
            if (val & 1) break;
            ++k;
            val >>= 1;
        }
        return (memo[u][v][val] = dp[u][v][k]);
    }
    else {
        int tval = val;
        int k = 0;
        while (tval > 0) {
            if (tval & 1) break;
            ++k;
            tval >>= 1;
        }
        ll res = INF2;
        int n = sz(dp);
        rep(u2, n) {
            res = min(res, dp[u][u2][k]+calc(u2, v, val&(~(1<<k))));
        }
        return (memo[u][v][val] = res);
    }
}
class AtLeastKDays {
public:
    ll sumOfMinCosts(vs costs, int minDays) {
        int n = sz(costs), kmax = 0;
        while ((1<<kmax) < minDays) ++kmax;
        if (kmax < 1) kmax = 1;
        dp = vector<vector<vll>>(n, vector<vll>(n, vll(kmax+2, INF2)));
        rep(u, n) rep(v, n) {
            if (u != v) dp[u][v][0] = costs[u][v] - '0';
        }
        rep(k, kmax+1) {
            rep(u, n) rep(v, n) {
                rep(u2, n) dp[u][v][k+1] = min(dp[u][v][k+1], min((ll)(INF2), dp[u][u2][k]+dp[u2][v][k]));
            }
        }
        repr(k, kmax+1) rep(u, n) rep(v, n) dp[u][v][k] = min(dp[u][v][k], dp[u][v][k+1]);
        rep(k, kmax+1) rep(u, n) rep(v, n) {
            rep(u2, n) dp[u][v][k+1] = min(dp[u][v][k+1], dp[u][u2][k]+dp[u2][v][k]);
        }
        memo = vector<vector<map<int, ll>>>(n, vector<map<int, ll>>(n));
        ll res = 0;
        rep(u, n) rep(v, n) res += calc(u, v, minDays);
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vs c(n);
    rep(i, n) cin >> c[i];
    int md;
    cin >> md;
    AtLeastKDays cl;
    cout << cl.sumOfMinCosts(c, md) << endl;
    return 0;
}
