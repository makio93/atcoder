#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size(), n = m + 1;
        vector<vector<int>> g(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]-1].push_back(edges[i][1]-1);
            g[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        int res = -1;
        for (int i=0; i<n; ++i) if ((int)(g[i].size()) == n-1) res = i+1;
        return res;
    }
};

int main(){
    return 0;
}
