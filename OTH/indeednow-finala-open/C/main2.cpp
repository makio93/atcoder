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
    vector<pair<int, tuple<int, int, int>>> w(n);
    rep(i, n) cin >> get<0>(w[i].second) >> get<1>(w[i].second) >> get<2>(w[i].second) >> w[i].first;
    vi x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    RSORT(w);
    vector<vector<vi>> dp(101, vector<vi>(101, vi(101)));
    rep(h, n) {
        for (int i=get<0>(w[h].second); i<=100; ++i) {
            bool askip = true;
            for (int j=get<1>(w[h].second); j<=100; ++j) {
                bool skip = true;
                for (int k=get<2>(w[h].second); k<=100; ++k) {
                    if (dp[i][j][k] != 0) break;
                    dp[i][j][k] = w[h].first;
                    askip = skip = false;
                }
                if (skip) break;
            }
            if (askip) break;
        }
    }
    rep(i, m) cout << dp[x[i]][y[i]][z[i]] << endl;
    return 0;
}
