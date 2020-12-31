#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> ans;
int dfs(int v) {
    int res = 0;
    for (int t : g[v]) res += dfs(t);
    ans[v] = res;
    return res + 1;
}

int main() {
    int n;
    cin >> n;
    g = vector<vector<int>>(n);
    for (int i=1; i<n; ++i) {
        int ai;
        cin >> ai;
        --ai;
        g[ai].push_back(i);
    }
    ans = vector<int>(n);
    dfs(0);
    for (int i=0; i<n; ++i) cout << ans[i] << endl;
    return 0;
}
