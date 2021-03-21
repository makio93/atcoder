#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

//const long long mod = 998244353;
using mint = modint998244353;

int main(){
    int n, m;
    cin >> n >> m;
    v(int) a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    v(v(v(mint))) dp(m+1, v(v(mint))(n, v(mint)(2)));
    rep(i, n) {
        dp[0][i][0] = 1;
        dp[0][i][1] = 0;
    }
    rep2(i, 1, m) {
        int ai = a[i-1], bi = b[i-1];
        if (ai > bi) swap(ai, bi);
        rep(j, n) {
            if (j < ai) {
                dp[i][j][0] += dp[i-1][j][0] * 2;
                dp[i][j][1] += dp[i-1][j][1] * 2;
            }
            else if (j < bi) {
                dp[i][j][0] += dp[i-1][j][1] * 2;
                dp[i][j][1] += dp[i-1][j][0] * 2;
            }
            else {
                dp[i][j][0] += dp[i-1][j][0] * 2;
                dp[i][j][1] += dp[i-1][j][1] * 2;
            }
        }
    }
    
    return 0;
}
