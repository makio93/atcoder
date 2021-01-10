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

v(int) a, b;
v(bool) visited;
v(v(int)) g;
void dfs(int v, int val) {
    if (visited[v] && b[v]>=val) return;
    visited[v] = true;
    b[v] = val;
    val = max(val, a[v]);
    for (int to : g[v]) dfs(to, val);
}

int main(){
    int n, m;
    cin >> n >> m;
    a = v(int)(n);
    b = v(int)(n);
    rep(i, n) cin >> a[i];
    visited = v(bool)(n);
    g = v(v(int))(n);
    rep(i, m) {
        int xi, yi;
        cin >> xi >> yi;
        --xi; --yi;
        g[yi].pb(xi);
    }
    repr(i, n) {
        if (visited[i]) continue;
        dfs(i, (int)(-1e9)-5);
    }
    int ans = (int)(-1e9)-5;
    rep(i, n) {
        if (b[i] == (int)(-1e9)-5) continue;
        ans = max(ans, b[i]-a[i]);
    }
    cout << ans << endl;
    return 0;
}
