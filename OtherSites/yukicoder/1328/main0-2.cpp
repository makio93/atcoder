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

// yukicoderアドカレ2020y:DFSで書いてみる、解けない

v(int) c, x, y;
vp(int) sid;
set<int> unused;
v(int) cnt(2);
bool dfs(int v, v(int)& ans) {
    if (v == sz(ans)) return true;
    auto itr = unused.begin();
    v(bool) ng(2);
    while (itr != unused.end()) {
        int tid = *itr;
        int id = sid[tid].second, ci = c[id], xi = x[id], yi = y[id];
        if (cnt[xi] > yi) return false;
        if (cnt[xi] != yi) {
            if (ng[0] && ng[1]) return false;
            ng[xi] = true;
            ++itr;
            continue;
        }
        ans[v] = id+1; cnt[ci]++; itr = unused.erase(itr);
        bool res = dfs(v+1, ans);
        if (res) return true;
        ans[v] = 0; cnt[ci]--;
        itr = unused.insert(itr, tid);
        ++itr;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    c = v(int)(n); x = v(int)(n); y = v(int)(n);
    rep(i, n) {
        char ci, xi;
        cin >> ci >> xi >> y[i];
        c[i] = (ci=='R'?0:1);
        x[i] = (xi=='R'?0:1);
    }
    sid = vp(int)(n);
    rep(i, n) sid[i] = { y[i], i };
    VSORT(sid);
    rep(i, n) unused.insert(i);
    v(int) ans(n);
    if (dfs(0, ans)) {
        cout << "Yes" << endl;
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    }
    else cout << "No" << endl;
    return 0;
}
