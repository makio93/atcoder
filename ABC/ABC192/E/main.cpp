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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    --x; --y;
    v(v(p(int))) g(n);
    v(ll) t(m), k(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b >> t[i] >> k[i];
        --a; --b;
        g[a].eb(b, i);
        g[b].eb(a, i);
    }
    priority_queue<p2(ll,int),v(p2(ll,int)),greater<p2(ll,int)>> que;
    v(ll) dist(n, (ll)(LINF));
    que.emplace(0LL, x);
    dist[x] = 0LL;
    while (!que.empty()) {
        auto pi = que.top(); que.pop();
        ll nt = pi.first;
        int vv = pi.second;
        if (dist[vv] != nt) continue;
        rep(i, sz(g[vv])) {
            int tov = g[vv][i].first, nmi = g[vv][i].second;
            ll tt = (nt+k[nmi]-1)/k[nmi]*k[nmi] + t[nmi];
            if (dist[tov] <= tt) continue;
            que.emplace(tt, tov);
            dist[tov] = tt;
        }
    }
    if (dist[y] == (ll)(LINF)) cout << -1 << endl;
    else cout << dist[y] << endl;
    return 0;
}
