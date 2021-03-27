#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int t;
    cin >> t;
    rep2(i1, 1, t) {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int n = s.length();
        v(v(int)) dp(n+1, v(int)(2, (int)(INF)));
        dp[0][0] = dp[0][1] = 0;
        rep(i, n) {
            if (s[i] == 'C') {
                rep(j, 2) if (dp[i][j] < (int)(INF)) {
                    if (j == 1) dp[i+1][0] = min(dp[i+1][0], dp[i][j]+y);
                    else dp[i+1][0] = min(dp[i+1][0], dp[i][j]);
                }
            }
            else if (s[i] == 'J') {
                rep(j, 2) if (dp[i][j] < (int)(INF)) {
                    if (j == 0) dp[i+1][1] = min(dp[i+1][1], dp[i][j]+x);
                    else dp[i+1][1] = min(dp[i+1][1], dp[i][j]);
                }
            }
            else {
                rep(j, 2) if (dp[i][j] < (int)(INF)) {
                    if (j == 0) dp[i+1][1-j] = min(dp[i+1][1-j], dp[i][j]+x);
                    else dp[i+1][1-j] = min(dp[i+1][1-j], dp[i][j]+y);
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                }
            }
        }
        int res = min(dp[n][0], dp[n][1]);
        cout << "Case #" << i1 << ": " << res << endl;
    }
    return 0;
}
