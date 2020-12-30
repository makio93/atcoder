#include <bits/stdc++.h>
using namespace std;

int main(){
    int w;
    cin >> w;
    vector<string> s(2);
    for (int i=0; i<2; ++i) cin >> s[i];
    vector<vector<int>> dp(w+1, vector<int>(2));
    for (int i=1; i<=w; ++i) {
        for (int j=0; j<2; ++j) {
            if (i-1 == 0) dp[i][j] = 1;
            if (i-1 > 0) {
                if (s[j][i-2] != s[j][i-1]) dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = 1;
            }
        }
        if (s[0][i-1] != s[1][i-1]) {
            vector<int> tdp = dp[i];
            for (int j=0; j<2; ++j) dp[i][j] = max(dp[i][j], tdp[1-j]+1);
        }
    }
    int ans = 0;
    for (int i=1; i<=w; ++i) for (int j=0; j<2; ++j) ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}
