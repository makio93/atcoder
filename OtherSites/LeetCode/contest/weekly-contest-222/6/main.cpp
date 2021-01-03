#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size(), m = arr.size();
        map<int, set<int>> place;
        for (int i=0; i<m; ++i) place[arr[i]].insert(i);
        vector<int> dp(n+1, (int)(1e9+5));
        dp[0] = -1;
        for (int i=0; i<n; ++i) {
            if (place.find(target[i]) == place.end()) continue;
            if (place[target[i]].size() == 1) {
                int p = *place[target[i]].begin();
                *upper_bound(dp.begin(), dp.end(), p) = p;
            }
            else {
                int p = *place[target[i]].rbegin();
                int d = distance(dp.begin(), upper_bound(dp.begin(), dp.end(), p));
                dp[d] = p;
                for (int j=d-1; j>0; --j) {
                    auto sitr = place[target[i]].lower_bound(dp[j]);
                    if (sitr == place[target[i]].begin()) break;
                    --sitr;
                    int d2 = distance(dp.begin(), upper_bound(dp.begin(), dp.end(), *sitr));
                    dp[d2] = *sitr;
                }
            }
            place.erase(target[i]);
        }
        int mlen = distance(dp.begin(), lower_bound(dp.begin(), dp.end(), (int)(1e9+5))) - 1;
        return (n - mlen);
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<int> target(n), arr(m);
    for (int i=0; i<n; ++i) cin >> target[i];
    for (int i=0; i<m; ++i) cin >> arr[i];
    int res = cl.minOperations(target, arr);
    cout << res << endl;
    return 0;
}
