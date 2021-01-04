#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i=0; i<m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        --a; --b;
        if (t == 0) uf.unite(a, b);
        else {
            if (uf.same(a, b)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
