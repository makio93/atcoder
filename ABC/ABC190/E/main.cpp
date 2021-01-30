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

int main(){
    int n, m;
    cin >> n >> m;
    v(int) a(m), b(m);
    v(v(int)) g(n);
    rep(i, m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    int k;
    cin >> k;
    v(int) c(k);
    rep(i, k) {
        cin >> c[i];
        c[i]--;
    }
    if (k<=1) {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<ll>> dist(k, vector<ll>(k, (ll)(1e18)));
    rep(i, k) {
        queue<int> que;
        vector<ll> ndist(n, (ll)(1e18));
        que.push(c[i]);
        ndist[c[i]] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            ll d = ndist[vi], nd = d + 1;
            rep(j, sz(g[vi])) {
                if (ndist[g[vi][j]] <= nd) continue;
                que.push(g[vi][j]);
                ndist[g[vi][j]] = nd;
            }
        }
        rep(j, k) dist[i][j] = ndist[c[j]];
    }
    vector<vector<ll>> dp((1<<k), vector<ll>(k, (ll)(1e18)));
    rep(i, k) dp[(1<<k)-1][i] = 0;
    repr(i, ((1<<k)-2)) {
        rep(vi, k) rep(ui, k) {
            if (!((i>>ui)&1)) dp[i][vi] = min(dp[i][vi], min((ll)(1e18), dp[i|(1<<ui)][ui]+dist[vi][ui]));
        }
    }
    ll ans = (ll)(1e18);
    rep(i, k) ans = min(ans, dp[0][i]);
    if (ans != (ll)(1e18)) cout << (ans+1) << endl;
    else cout << -1 << endl;
    return 0;
}
