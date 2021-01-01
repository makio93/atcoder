#include <bits/stdc++.h>
using namespace std;

int main() {
    long long s;
    int p;
    cin >> s >> p;
    vector<long long> dp(p+1, 0LL);
    dp[0] = s;
    for (int i=0; i<p; ++i) for (int j=i+1; j<=p; ++j) {
        dp[j] = max(dp[j], dp[i]*(100+(j-i))/100);
    }
    cout << dp[p] << endl;
    return 0;
}
