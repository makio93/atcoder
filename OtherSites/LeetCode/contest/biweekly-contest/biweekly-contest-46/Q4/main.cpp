#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> g;
    vector<stack<pair<int,int>>> anc;
    vector<int> ans;
    void dfs(vector<int>& nums, int v, int p=-1, int d=0) {
        int nval = nums[v];
        pair<int, int> aval = { -1, -1 };
        for (int i=1; i<=50; ++i) if (gcd(i,nval)==1 && !anc[i].empty()) aval = max(aval, anc[i].top());
        if (aval.first != -1) ans[v] = aval.second;
        anc[nval].emplace(d, v);
        for (int i=0; i<(int)(g[v].size()); ++i) {
            int to = g[v][i];
            if (to == p) continue;
            dfs(nums, to, v, d+1);
        }
        anc[nval].pop();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        g = vector<vector<int>>(n);
        for (int i=0; i<n-1; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        anc = vector<stack<pair<int,int>>>(51);
        ans = vector<int>(n, -1);
        dfs(nums, 0);
        return ans;
    }
};

int main(){
    return 0;
}
