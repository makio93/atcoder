#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> g(n);
        int m = edges.size();
        for (int i=0; i<m; ++i) {
            int v1 = edges[i][0]-1, v2 = edges[i][1]-1;
            if (v1 > v2) swap(v1, v2);
            g[v1].insert(v2);
            g[v2].insert(v1);
        }
        int mval = (int)(1e9);
        for (int i=0; i<n; ++i) {
            int len = g[i].size();
            for (auto itr=g[i].lower_bound(i+1); itr!=g[i].end(); ++itr) for (auto itr2=next(itr); itr2!=g[i].end(); ++itr2) {
                if (g[*itr].find(*itr2) != g[*itr].end()) {
                    int tval = (int)(g[i].size()) + (int)(g[*itr].size()) + (int)(g[*itr2].size()) - 6;
                    mval = min(mval, tval);
                }
            }
        }
        if (mval == (int)(1e9)) return -1;
        else return mval;
    }
};

int main(){
    return 0;
}
