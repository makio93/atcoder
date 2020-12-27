#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> x(n), y(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> y[i];
    vector<vector<int>> d(n, vector<int>(n));
    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
        int dxi = min(abs(x[i]-x[j]), w-abs(x[i]-x[j]));
        int dyi = min(abs(y[i]-y[j]), h-abs(y[i]-y[j]));
        d[i][j] = d[j][i] = dxi + dyi;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    set<int> visited;
    int ans = 0;
    q.emplace(0, 0);
    int now = -1;
    while ((int)(visited.size()) < n) {
        auto p = q.top(); q.pop();
        int vd = p.first, vp = p.second;
        if (visited.find(vp) != visited.end()) continue;
        ans += vd;
        visited.insert(vp);
        now = vp;
        for (int i=0; i<n; ++i) {
            if (visited.find(i) != visited.end()) continue;
            q.emplace(d[now][i], i);
        }
    }
    cout << ans << endl;
    return 0;
}
