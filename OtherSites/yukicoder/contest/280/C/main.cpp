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
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n);
        rep(i, n) cin >> a[i];
        rep(i, 2) a.pb(a[i]);
        v(bool) b(n, true);
        rep(i, n) {
            if (a[i]==a[i+1] || a[i]==a[i+2] || a[i+1]==a[i+2]) b[i] = false;
            if (!(a[i+1]<a[i]&&a[i+1]<a[i+2]) && !(a[i+1]>a[i]&&a[i+1]>a[i+2])) b[i] = false;
        }
        v(v(v(ll))) dp(3, v(v(ll))(n-1, v(ll)(2)));
        rep(k, 3) rep2(i, 1, n-2) {
            dp[k][i][0] = max(dp[k][i][0], max(dp[k][i-1][0], dp[k][i-1][1]));
            ll pval = (i-3>=0?max(dp[k][i-3][0],dp[k][i-3][1]):0), add = (b[i+k-1]?a[i+k-1]:0);
            dp[k][i][1] = max(dp[k][i][1], pval+add);
        }
        ll ans = 0;
        rep(i, 3) rep(j, 2) ans = max(ans, dp[i][n-2][j]);
        cout << ans << endl;
    }
    return 0;
}
