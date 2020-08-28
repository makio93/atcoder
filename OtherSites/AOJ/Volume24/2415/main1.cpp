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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    vll w(n), s(n+1);
    rep(i, n) cin >> w[i];
    rep(i, n) s[i+1] = s[i] + w[i];
    vector<vll> dp(n+1, vll(n+1));
    vector<vi> k(n+1, vi(n+1));
    rep(i, n) k[i][i+1] = i+1;
    rep1(h, n) for (int i=0; i+h<=n; ++i) {
        if (h<=1) dp[i][i+h] = 0;
        else {
            ll val = INF; int idx = -1;
            for (int j=k[i][i+h-1]; j<=k[i+1][i+h]; ++j) {
                if (dp[i][j]+dp[j][i+h] < val) {
                    val = dp[i][j]+dp[j][i+h]; idx = j;
                }
            }
            dp[i][i+h] = val + (s[i+h]-s[i]); k[i][i+h] = idx;
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}
