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
        map<int, map<int, int>> scnt, tcnt;
        for (int i=0; i<n; ++i) {
            int group = uf.find(i);
            scnt[group][source[i]]++;
            tcnt[group][target[i]]++;
        }
        int dist = 0, gnum = scnt.size();
        auto sitr = scnt.begin(), titr = tcnt.begin();
        for (int i=0; i<gnum; ++i) {
            map<int, pair<int, int>> difs;
            for (auto p2 : sitr->second) difs[p2.first].first += p2.second;
            for (auto p2 : titr->second) difs[p2.first].second += p2.second;
            int dif = 0;
            for (auto p2 : difs) dif += abs(p2.second.first - p2.second.second);
            dist += dif / 2;
            ++sitr; ++titr;
        }
        return dist;
    }
};

int main(){
    
    return 0;
}
