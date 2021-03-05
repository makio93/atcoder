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

v(v(v(int))) visited;
v(v(v(bool))) searched;
bool dfs(v(vp(int))& g, int b, int vi, int val, int pi=-1) {
    if (searched[b][vi][val]) return true;
    if (searched[b][vi][1-val]) return false;
    if (visited[b][vi][val] != -1) return (visited[b][vi][val] == 1);
    searched[b][vi][val] = true;
    visited[b][vi][val] = 1;
    bool ans = true;
    rep(i, sz(g[vi])) {
        int to = g[vi][i].first;
        if (to == pi) continue;
        int tval = ((g[vi][i].second>>b)&1) ^ val;
        ans &= dfs(g, b, to, tval, vi);
    }
    visited[b][vi][val] = (ans?1:0);
    searched[b][vi][val] = false;
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    v(vp(int)) g(n);
    rep(i, m) {
        int a, b, y;
        cin >> a >> b >> y;
        --a; --b;
        g[a].eb(b,y);
        g[b].eb(a,y);
    }
    visited = v(v(v(int)))(30, v(v(int))(n, v(int)(2, -1)));
    searched = v(v(v(bool)))(30, v(v(bool))(n, v(bool)(2)));
    rep(i, 30) rep(j, n) {
        bool now = false;
        rep(j2, 2) now |= dfs(g, i, j, j2);
        if (!now) {
            cout << -1 << endl;
            return 0;
        }
    }
    v(int) x(n);
    rep(i, 30) rep(j, n) rep(j2, 2) {
        if (visited[i][j][j2] == 1) {
            if (j2 == 1) x[j] |= (1 << i);
            break;
        }
    }
    rep(i, n) cout << x[i] << endl;
    return 0;
}
