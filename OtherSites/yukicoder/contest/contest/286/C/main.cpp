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
    int n;
    cin >> n;
    v(v(int)) g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].pb(bi);
        g[bi].pb(ai);
    }
    bool ok = false;
    int leaf = 0, cent = -1;
    rep(i, n) if (sz(g[i]) == 1) ++leaf;
    if (leaf <= 2) ok = true;
    else {
        rep(i, n) if (sz(g[i]) == leaf) cent = i;
        if (cent != -1) {
            queue<int> que;
            v(int) dist(n, (int)(INF));
            que.push(cent);
            dist[cent] = 0;
            v(int) dlst;
            while (!que.empty()) {
                int pi = que.front(); que.pop();
                int d = dist[pi], nd = d+1;
                if (sz(g[pi])==1 && pi!=cent) dlst.pb(d);
                rep(j, sz(g[pi])) {
                    int to = g[pi][j];
                    if (dist[to] <= nd) continue;
                    que.push(to);
                    dist[to] = nd;
                }
            }
            bool ok2 = true;
            rep(i, sz(dlst)-1) if (dlst[i] != dlst[i+1]) ok2 = false;
            if (ok2) ok = true;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
