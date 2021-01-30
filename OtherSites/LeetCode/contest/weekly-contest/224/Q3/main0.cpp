#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        set<int> rlst;
        for (int i=0; i<m; ++i) rlst.insert(i);
        vector<pair<int, int>> rbit(n);
        for (int i=0; i<n; ++i) rbit[i].second = i;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (matrix[i][j] == 1) rbit[i].first++;
        sort(rbit.begin(), rbit.end(), greater<pair<int, int>>{});
        int ans = 0;
        for (int i1=0; i1<n; ++i1) {
            if (rbit[i1].first == 0) break;
            ans = max(ans, (i1+1)*(rbit[i1].first));
            rlst.erase(rbit[i1].second);
            for (int i=i1+1; i<n; ++i) for (int j=0; j<m; ++j) {
                if (matrix[rbit[i1].second][j]==0 && matrix[rbit[i].second][j]==1) rbit[i].first--;
            }
            sort(rbit.begin()+i1+1, rbit.end(), greater<pair<int, int>>{});
        }
        return ans;
    }
};

int main(){

    return 0;
}
