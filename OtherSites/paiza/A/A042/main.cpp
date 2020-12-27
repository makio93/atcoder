#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<vector<int>> memo;
int search(int v, int l) {
    if (memo[v][l] != -1) return memo[v][l];
    if (l == 0) {
        if (v == 0) return (memo[v][l] = 0);
        else return (memo[v][l] = -10);
    }
    int res = -10;
    if (v == 0) res = 0;
    for (auto p : g[v]) {
        int nt = p.first, nd = p.second;
        if (l-nd < 0) continue;
        int ret = search(nt, l-nd);
        if (ret == -10) continue;
        res = max(res, nd+ret);
    }
    return (memo[v][l] = res);
}

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    g = vector<vector<pair<int, int>>>(n);
    for (int i=0; i<m; ++i) {
        int si, ti, di;
        cin >> si >> ti >> di;
        --si; --ti;
        g[si].emplace_back(ti, di);
    }
    memo = vector<vector<int>>(n, vector<int>(l+1, -1));
    cout << search(0, l) << endl;
    return 0;
}
