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

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n;
        vi r(n);
        rep(i, n) cin >> r[i];
        cin >> m;
        vi b(m);
        rep(i, m) cin >> b[i];
        vector<vi> dp(n+1, vi(m+1, (int)(-1e9)));
        dp[0][0] = 0;
        rep(i, n+1) rep(j, m+1) {
            if (i < n) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+r[i]);
            if (j < m) dp[i][j+1] = max(dp[i][j+1], dp[i][j]+b[j]);
        }
        int ans = (int)(-1e9);
        rep(i, n+1) rep(j, m+1) ans = max(ans, dp[i][j]);
        cout << ans << endl;
    }
    return 0;
}
