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
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s; --t;
    v(int) pi(n);
    rep(i, n) cin >> pi[i];
    v(v(int)) g(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        g[ai].pb(bi);
        g[bi].pb(ai);
    }
    vp(int) dist(n, {-1,-1});
    priority_queue<p2(p(int),int)> que;
    que.emplace(make_pair(0,pi[s]), s);
    dist[s] = { 0, pi[s] };
    while (!que.empty()) {
        auto p1 = que.top(); que.pop();
        int vy = p1.first.first, vx = p1.first.second, vi = p1.second;
        if (dist[vi] != p(int){vy,vx}) continue;
        rep(i, sz(g[vi])) {
            int ni = g[vi][i], ny, nx;
            if (vx > pi[ni]) {
                ny = vy + 1;
                nx = pi[ni];
            }
            else {
                ny = vy;
                nx = vx;
            }
            if (dist[ni].first>=ny&&dist[ni].second>=nx) continue;
            que.emplace(make_pair(ny, nx), ni);
            dist[ni] = { ny, nx };
        }
    }
    cout << dist[t].first << endl;
    return 0;
}
