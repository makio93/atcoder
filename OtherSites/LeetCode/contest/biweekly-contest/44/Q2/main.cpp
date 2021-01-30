#include <bits/stdc++.h>
using namespace std;

class Solution {
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
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        UnionFind uf(m);
        for (int i=0; i<(int)(friendships.size()); ++i) {
            uf.unite(friendships[i][0]-1, friendships[i][1]-1);
        }
        map<int, set<int>> groups;
        for (int i=0; i<m; ++i) {
            groups[uf.find(i)].insert(i);
        }
        int ans = 0;
        for (auto p : groups) {
            vector<int> lcnt(n);
            for (auto p2 : p.second) for (int j=0; j<(int)(languages[p2].size()); ++j) {
                lcnt[languages[p2][j]-1]++;
            }
            int mval = 0;
            for (int i=0; i<n; ++i) mval = max(mval, lcnt[i]);
            ans += (int)(p.second.size()) - mval;
        }
        return ans;
    }
};

int main(){
    return 0;
}
