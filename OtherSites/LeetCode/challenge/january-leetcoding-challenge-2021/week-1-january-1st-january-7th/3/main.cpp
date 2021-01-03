#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
vector<int> perm;
void dfs(int d, int& n, int& ans) {
    if (d == n) {
        ++ans;
        return;
    }
    for (int i=0; i<n; ++i) {
        if (used[i]) continue;
        if (!((d+1)%(i+1)==0||(i+1)%(d+1)==0)) continue;
        used[i] = true;
        perm[d] = i+1;
        dfs(d+1, n, ans);
        perm[d] = 0;
        used[i] = false;
    }
}

class Solution {
public:
    int countArrangement(int n) {
        used = vector<bool>(n);
        perm = vector<int>(n);
        int ans = 0;
        dfs(0, n, ans);
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    int res = cl.countArrangement(n);
    cout << res << endl;
    return 0;
}
