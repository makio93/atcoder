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

// 本番終了後、自力研究

int isfib(int n) {
    int val1 = 1, val2 = 1;
    while (val1+val2 < n) {
        int tval = val1 + val2;
        val2 = val1;
        val1 = tval;
    }
    if (val1+val2 == n) return val1;
    else return -1;
}

v(int) memo;
int dfs(v(v(int))& g, int vi, int pi=-1) {
    int res = 0;
    rep(i, sz(g[vi])) {
        int to = g[vi][i];
        if (to == pi) continue;
        res += dfs(g, to, vi);
    }
    ++res;
    return (memo[vi] = res);
}

int main() {
    int n;
    cin >> n;
    v(v(int)) g(n);
    rep(i, n-1) {
        int u, vi;
        cin >> u >> vi;
        u--; vi--;
        g[u].pb(vi);
        g[vi].pb(u);
    }
    if (n == 1) {
        cout << "YES" << endl;
        return 0;
    }
    int fib = isfib(n);
    if (fib == -1) {
        cout << "NO" << endl;
        return 0;
    }
    memo = v(int)(n, -1);
    dfs(g, 0);
    bool ok = false;
    rep(i, n) if (memo[i]==fib||memo[i]==n-fib) ok = true;
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
