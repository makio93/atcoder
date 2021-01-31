#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size(), m = queries.size();
        vector<bool> ans(m);
        vector<long long> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + candiesCount[i];
        for (int i=0; i<m; ++i) {
            long long mxval = (long long)(queries[i][1]+1) * queries[i][2], mnval = queries[i][1];
            if (!(sum[queries[i][0]+1]<=mnval || sum[queries[i][0]]>=mxval)) ans[i] = true;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<int> candiesCount(n);
    for (int i=0; i<n; ++i) cin >> candiesCount[i];
    vector<vector<int>> queries(m, vector<int>(3));
    for (int i=0; i<m; ++i) for (int j=0; j<3; ++j) cin >> queries[i][j];
    vector<bool> ans = cl.canEat(candiesCount, queries);
    for (int i=0; i<m; ++i) {
        if (ans[i]) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
