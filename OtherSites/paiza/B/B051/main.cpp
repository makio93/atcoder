#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> m[i][j];
    vector<int> cnt(n*n+1, 0);
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cnt[m[i][j]]++;
    vector<int> nums;
    for (int i=1; i<=n*n; ++i) if (cnt[i] == 0) nums.push_back(i);
    vector<pair<int, int>> place;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (m[i][j] == 0) place.emplace_back(i, j);
    for (int i=0; i<2; ++i) {
        auto t = m;
        t[place[0].first][place[0].second] = nums[i];
        t[place[1].first][place[1].second] = nums[1-i];
        bool ok = true;
        int tval = 0;
        for (int i=0; i<n; ++i) {
            int sum = 0;
            for (int j=0; j<n; ++j) sum += t[i][j];
            if (i == 0) tval = sum;
            else if (sum != tval) ok = false;
        }
        for (int j=0; j<n; ++j) {
            int sum = 0;
            for (int i=0; i<n; ++i) sum += t[i][j];
            if (sum != tval) ok = false;
        }
        int sum = 0;
        for (int i=0; i<n; ++i) sum += t[i][i];
        if (sum != tval) ok = false;
        sum = 0;
        for (int i=0; i<n; ++i) sum += t[i][n-i-1];
        if (sum != tval) ok = false;
        if (ok) {
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
                printf("%d%c", t[i][j], (j<n-1?' ':'\n'));
            }
            break;
        }
    }
    return 0;
}
