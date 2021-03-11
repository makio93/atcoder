#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, (int)(1e9));
        dp[0] = 0;
        for (int i=0; i<n; ++i) for (int j=1; j<=amount; ++j) {
            if (j-coins[i] >= 0) dp[j] = min(dp[j], dp[j-coins[i]]+1);
        }
        return (dp[amount]==(int)(1e9)?-1:dp[amount]);
    }
};

int main(){
    Solution cl;
    int n, amount;
    cin >> n;
    vector<int> coins(n);
    for (int i=0; i<n; ++i) cin >> coins[i];
    cin >> amount;
    cout << cl.coinChange(coins, amount) << endl;
    return 0;
}
