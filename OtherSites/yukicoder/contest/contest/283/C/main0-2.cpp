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

// 書き直したけど結局わからん

int vi;
map<ll, v(int)> memo;
bool calc(v(v(v(bool)))& dp, ll dist, int i) {
    if (memo.find(dist) != memo.end()) {
        if (memo[dist][i] != -1) return (memo[dist][i] == 1);
    }
    else {
        memo[dist] = v(int)(vi, -1);
    }
    if (dist == 0) {
        memo[dist][i] = 0;
        return (memo[dist][i] == 1);
    }
    int nowk = 0;
    for (int i2=0; (dist>>i2)>0; ++i2) {
        if ((dist>>i2)&1) {
            nowk = i2;
            break;
        }
    }
    bool ans = false, ok = false;
    ll ndist = dist&(~(1LL<<nowk));
    rep(i2, vi) {
        if (dp[nowk][i][i2]) {
            ans = ans || calc(dp, ndist, i2);
        }
        else ok = false;
    }
    if (ok) ans = true;
    memo[dist][i] = (ans?1:0);
    return (memo[dist][i] == 1);
}

int main(){
    ll d;
    cin >> vi >> d;
    v(string) e(vi);
    rep(i, vi) cin >> e[i];
    int bcnt = 0;
    for (int i=0; (d>>i)>0LL; ++i) ++bcnt;
    v(v(v(bool))) dp(bcnt, v(v(bool))(vi, v(bool)(vi)));
    rep(i, vi) rep(j, vi) {
        if (e[i][j] == '1') dp[0][i][j] = true;
    }
    rep(k, bcnt-1) rep(i, vi) rep(j, vi) {
        if (!dp[k][i][j]) continue;
        rep(j2, vi) dp[k+1][i][j2] = dp[k+1][i][j2] || dp[k][j][j2];
    }

    /*
    bool ans = true;
    rep(i1, vi) {
        v(bool) ok = dp[0][i1];
        rep(i, bcnt) if ((d>>i)&1) {
            v(bool) nok(vi);
            rep(j, vi) if (ok[j]) rep(j2, vi) {
                nok[j2] = nok[j2] || dp[i][j][j2];
            }
            swap(ok, nok);
        }
        rep(i, vi) if (!ok[i]) {
            ans = false;
        }
        if (!ans) break;
    }
    */
    bool ans = true;
    rep(i, vi) ans = ans && calc(dp, d, i);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
