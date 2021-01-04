#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, g, m;
    cin >> n >> g >> m;
    vector<vector<int>> a(g);
    for (int i=0; i<g; ++i) {
        int ki;
        cin >> ki;
        for (int j=0; j<ki; ++j) {
            int ai;
            cin >> ai;
            --ai;
            a[i].push_back(ai);
        }
    }
    vector<vector<string>> ans(n);
    for (int i=0; i<m; ++i) {
        int si, ci, ti;
        string msgi;
        cin >> si >> ci >> ti >> msgi;
        --si; --ti;
        if (ci == 0) {
            ans[si].push_back(msgi);
            ans[ti].push_back(msgi);
        }
        else {
            int ki = (int)(a[ti].size());
            for (int j=0; j<ki; ++j) ans[a[ti][j]].push_back(msgi);
        }
    }
    for (int i=0; i<n; ++i) {
        for (string logi : ans[i]) cout << logi << endl;
        if (i < n-1) cout << "--" << endl;
    }
    return 0;
}
