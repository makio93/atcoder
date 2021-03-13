#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long long mod = (long long)(1e9+7);
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> dp(n);
        for (int i=0; i<n; ++i) {
            dp[i] += 1;
            for (int j=0; j<i; ++j) {
                if (arr[i]%arr[j] != 0) continue;
                int id = lower_bound(arr.begin(), arr.begin()+i, arr[i]/arr[j]) - arr.begin();
                if (id>=i || id<j || arr[id]!=arr[i]/arr[j]) continue;
                long long mul = (arr[id]==arr[j]?1:2);
                dp[i] = (dp[i] + (dp[j] * dp[id]) % mod * mul) % mod;
            }
        }
        long long ans = 0;
        for (int i=0; i<n; ++i) ans = (ans + dp[i]) % mod;
        return (int)(ans);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    cout << cl.numFactoredBinaryTrees(arr) << endl;
    return 0;
}
