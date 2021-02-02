#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = -(prices.front()), store = prices.front();
        for (int i=0; i<n; ++i) {
            if (i+1>=n || prices[i+1]<prices[i]) {
                res += prices[i];
                store = 0;
                if (i+1<n) {
                    store += prices[i+1];
                    res -= prices[i+1];
                }
            }
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i=0; i<n; ++i) cin >> prices[i];
    cout << cl.maxProfit(prices) << endl;
    return 0;
}
