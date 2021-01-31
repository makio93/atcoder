#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        map<int, int> cnt;
        map<int, vector<int>> g;
        for (int i=0; i<n; ++i) {
            cnt[adjacentPairs[i][0]]++;
            cnt[adjacentPairs[i][1]]++;
            g[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            g[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int tnum = (int)(-1e9), pnum = (int)(-1e9);
        for (auto p : cnt) if (p.second == 1) {
            tnum = p.first;
            break;
        }
        vector<int> ans;
        ans.push_back(tnum);
        while (1) {
            bool ok = false;
            for (int i=0; i<(int)(g[tnum].size()); ++i) {
                if (g[tnum][i] != pnum) {
                    ans.push_back(g[tnum][i]);
                    pnum = tnum;
                    tnum = g[tnum][i];
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<vector<int>> adjacentPairs(n-1, vector<int>(2));
    for (int i=0; i<n-1; ++i) cin >> adjacentPairs[i][0] >> adjacentPairs[i][1];
    vector<int> res = cl.restoreArray(adjacentPairs);
    for (int i=0; i<n; ++i) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    return 0;
}
