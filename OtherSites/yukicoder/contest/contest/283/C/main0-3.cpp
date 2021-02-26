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

// 本番終了後、改めて考察、自力AC

struct UnionFind {
    vector<int> par;
    UnionFind(int n=0): par(n,-1) {}
    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -par[find(x)];}
};

bool dfs1(v(v(int))& g, v(int)& visited, int v1, int p1=-1, int d=0) {
    if (visited[v1] != -1) return (visited[v1]%2 != d%2);
    visited[v1] = d;
    bool res = false;
    rep(i, sz(g[v1])) {
        int nv = g[v1][i];
        if (nv == p1) continue;
        res |= dfs1(g, visited, nv, v1, d+1);
    }
    return res;
}

int main(){
    int vi;
    ll d;
    cin >> vi >> d;
    v(string) e(vi);
    rep(i, vi) cin >> e[i];
    v(v(int)) g(vi);
    rep(i, vi) for (int j=i; j<vi; ++j) if (e[i][j] == '1') {
        g[i].pb(j);
        g[j].pb(i);
    }
    if (d >= 2*vi) {
        UnionFind uf(vi);
        rep(i, vi) for (int j=i; j<vi; ++j) if (e[i][j] == '1') uf.unite(i, j);
        if (uf.size(0) < vi) cout << "No" << endl;
        else {
            v(int) visited(vi, -1);
            if (dfs1(g, visited, 0)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    else if (d > 1) {
        bool ans = true;
        rep(i, vi) {
            v(v(int)) dist(2, v(int)(vi, (int)(INF)));
            queue<int> que;
            que.push(i);
            dist[0][i] = 0;
            while (!que.empty()) {
                int pi = que.front(); que.pop();
                int d0 = dist[0][pi], d1 = dist[1][pi], nd1 = min((int)(INF), d0+1), nd0 = min((int)(INF), d1+1);
                rep(i2, sz(g[pi])) {
                    int nvi = g[pi][i2];
                    if (dist[0][nvi]<=nd0 && dist[1][nvi]<=nd1) continue;
                    que.push(nvi);
                    if (dist[0][nvi] > nd0) dist[0][nvi] = nd0;
                    if (dist[1][nvi] > nd1) dist[1][nvi] = nd1;
                }
            }
            rep(i2, vi) if (dist[(int)(d%2LL)][i2]==(int)(INF) || dist[(int)(d%2LL)][i2]>d) ans = false;
            if (!ans) break;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        bool ans = true;
        rep(i, vi) if (e[i] != string(vi, '1')) ans = false;
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
