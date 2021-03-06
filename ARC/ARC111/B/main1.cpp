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

map<int, v(int)> g;
map<int, bool> visited, finished;
bool loop(int v, int p) {
    if (visited[v]) return true;
    visited[v] = true;
    bool res = false;
    for (auto to : g[v]) {
        if (to == p) continue;
        if (finished[to]) continue;
        res |= loop(to, v);
    }
    visited[v] = false;
    finished[v] = true;
    return res;
}

int main(){
    int n;
    cin >> n;
    v(int) a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) {
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    int ncnt = 0;
    repi(itr, g) {
        if (!finished[itr->first]) {
            if (!loop(itr->first, -1)) ++ncnt;
        }
    }
    cout << (sz(g)-ncnt) << endl;
    return 0;
}
