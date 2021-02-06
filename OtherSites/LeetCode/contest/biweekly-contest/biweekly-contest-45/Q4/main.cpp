#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        map<int, pair<vector<int>,int>> sches;
        for (int i=0; i<n; ++i) sches[events[i][1]].first.push_back(i);
        int m = sches.size();
        auto itr = sches.begin();
        for (int i=0; i<m; ++i) {
            itr->second.second = i;
            ++itr;
        }
        vector<vector<long long>> dp(m+1, vector<long long>(k+1, (long long)(-1e15)));
        dp[0][0] = 0;
        for (int i=1; i<=m; ++i) dp[i][0] = 0;
        itr = sches.begin();
        for (int i=1; i<=m; ++i) {
            int nid = itr->second.second;
            auto tvec = itr->second.first;
            for (int j=0; j<(int)(tvec.size()); ++j) {
                int nid2 = tvec[j], tar = events[nid2][0], nval = events[nid2][2];
                auto titr = sches.lower_bound(tar);
                int pid = 0;
                if (titr == sches.begin()) pid = 0;
                else {
                    titr = prev(titr);
                    pid = titr->second.second + 1;
                }
                for (int j2=0; j2<=k; ++j2) {
                    if (j==0) dp[i][j2] = max(dp[i][j2], dp[i-1][j2]);
                    if (j2-1>=0) {
                        if (dp[pid][j2-1] != (long long)(-1e15)) {
                            dp[i][j2] = max(dp[i][j2], dp[pid][j2-1]+nval);
                        }
                    }
                    if (dp[pid][j2] != (long long)(-1e15)) {
                        dp[i][j2] = max(dp[i][j2], dp[pid][j2]);
                    }
                }
            }
            ++itr;
        }
        long long ans = 0;
        for (int i=0; i<=k; ++i) if (dp[m][i] != (long long)(-1e15)) ans = max(ans, dp[m][i]);
        return (int)(ans);
    }
};

int main(){
    return 0;
}
