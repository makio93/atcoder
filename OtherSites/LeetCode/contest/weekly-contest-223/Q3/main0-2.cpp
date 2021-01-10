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

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), m = allowedSwaps.size();
        UnionFind uf(n);
        for (int i=0; i<m; ++i) uf.unite(allowedSwaps[i][0], allowedSwaps[i][1]);
        map<int, map<int, pair<int, int>>> cnt;
        int add = 0;
        for (int i=0; i<n; ++i) {
            if (source[i] == target[i]) continue;
            int group = uf.find(i);
            if (uf.size(group) == 1) ++add;
            else {
                cnt[group][source[i]].first++;
                cnt[group][target[i]].second++;
            }
        }
        int dist = 0, gnum = cnt.size();
        auto citr = cnt.begin();
        for (int i=0; i<gnum; ++i) {
            int dif = 0;
            for (auto p2 : citr->second) dif += abs(p2.second.first - p2.second.second);
            dist += dif / 2;
            ++citr;
        }
        return (dist + add);
    }
};

int main(){
    
    return 0;
}
