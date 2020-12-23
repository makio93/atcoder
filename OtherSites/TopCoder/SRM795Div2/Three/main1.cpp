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

// 解説ブログを見てから作成したコード

vector<vll> Matmin(vector<vll>& a, vector<vll>& b, int n) {
    vector<vll> res(n, vll(n, INF2));
    rep(u, n) rep(v, n) {
        rep(t, n) res[u][v] = min(res[u][v], min((ll)(INF2), a[u][t]+b[t][v]));
    }
    return res;
}

class AtLeastKDays {
public:
    ll sumOfMinCosts(vs costs, int minDays) {
        int n = sz(costs);
        vector<vll> val(n, vll(n, INF2)), d(n, vll(n, INF2));
        rep(u, n) rep(v, n) {
            if (costs[u][v] == '-') continue;
            val[u][v] = costs[u][v] - '0';
        }
        auto a = val;
        rep(i, n) d[i][i] = 0;
        while (minDays > 0) {
            if (minDays & 1) d = Matmin(d, a, n);
            a = Matmin(a, a, n);
            minDays >>= 1;
        }
        auto dp = val;
        rep(k, n) rep(u, n) rep(v, n) {
            dp[u][v] = min(dp[u][v], min((ll)(INF2), dp[u][k]+dp[k][v]));
        }
        ll res = 0;
        rep(u, n) rep(v, n) {
            ll tmp = d[u][v];
            rep(k, n) tmp = min(tmp, d[u][k]+dp[k][v]);
            res += tmp;
        }
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
