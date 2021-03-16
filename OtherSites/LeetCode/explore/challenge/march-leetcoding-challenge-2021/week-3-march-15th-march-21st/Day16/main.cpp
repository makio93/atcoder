#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<long long>> dp(n, vector<long long>(2));
        dp[0][1] = dp[0][0] - prices[0];
        for (int i=1; i<n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][1] = max(dp[i][1], dp[i][0]-prices[i]);
        }
        return (int)max(dp[n-1][0], dp[n-1][1]);
    }
};

int main(){
    Solution cl;
    int n, fee;
    cin >> n;
    vector<int> prices(n);
    for (int i=0; i<n; ++i) cin >> prices[i];
    cin >> fee;
    cout << cl.maxProfit(prices, fee) << endl;
    return 0;
}
