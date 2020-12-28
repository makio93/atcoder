#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string g;
    cin >> g;
    vector<int> t(n+1);
    string tc = "NRL";
    for (int i=0; i<n; ++i) for (int j=0; j<3; ++j) if (g[i] == tc[j]) {
        if (j == 0) t[i+1] = t[i];
        else t[i+1] = t[i] ^ (1<<(j-1));
    }
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(4)));
    dp[0][0][0] = 1;
    for (int i=0; i<n; ++i) for (int j=0; j<=n; ++j) {
        for (int s=0; s<4; ++s) for (int s2=0; s2<3; ++s2) {
            int ns = s;
            if (s2 > 0) ns = ns ^ (1<<(s2-1));
            if (ns == t[i+1]) {
                if (j+1 <= n) dp[i+1][j+1][ns] += dp[i][j][s];
            }
            else dp[i+1][j][ns] += dp[i][j][s];
        }
    }
    long long ans = 0LL;
    for (int i=k; i<=n; ++i) for (int j=0; j<4; ++j) ans += dp[n][i][j];
    cout << ans << endl;
    return 0;
}
