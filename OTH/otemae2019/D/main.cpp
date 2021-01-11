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

// きまぐれ精進、自力AC

using mint = modint1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    v(int) s(m);
    rep(i, m) {
        const v(string) sval = { "", "Fizz", "Buzz", "FizzBuzz" };
        string si;
        cin >> si;
        rep(j, sz(sval)) if (si == sval[j]) s[i] = j;
    }
    v(v(v(mint))) dp(n+1, v(v(mint))(m+1, v(mint)(3)));
    dp[0][0][0] = 1;
    const v(v(int)) dkl = { { 3, 3, 2 }, { 1, 0, 1 } };
    rep(j, m+1) rep(i, n) rep(k, 3) {
        rep(dk, 3) {
            int nk = (k + dk) % 3;
            if (nk == 0) continue;
            dp[i+1][j][nk] += dp[i][j][k] * dkl[0][dk];
        }
        if (j+1 <= m) {
            rep(dk, 3) {
                int nk = (k + dk) % 3;
                if ((s[j]&1) xor (nk==0)) continue;
                if (i+1==1 && ((s[j]>>1)&1)==1 && dk==0) continue;
                dp[i+1][j+1][nk] += dp[i][j][k] * dkl[(s[j]>>1)&1][dk];
            }
        }
    }
    mint ans = 0;
    rep(i, 3) ans += dp[n][m][i];
    cout << ans.val() << endl;
    return 0;
}
