#include <bits/stdc++.h>
using namespace std;

// discussionの解答案の1つを見てから提出、AC

class Solution {
    vector<bool> used;
    bool dfs(vector<int>& ans, int i) {
        if (i == (int)(ans.size())) return true;
        if (ans[i] != 0) return dfs(ans, i+1);
        for (int j=used.size()-1; j>=0; --j) {
            if (used[j]) continue;
            if (!(j==0 || (j>0 && i+j+1<(int)(ans.size()) && ans[i+j+1]==0))) continue;
            used[j] = true;
            ans[i] = j+1;
            if (j>0) ans[i+j+1] = j+1;
            if (dfs(ans, i+1)) return true;
            used[j] = false;
            ans[i] = 0;
            if (j>0) ans[i+j+1] = 0;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1);
        used = vector<bool>(n);
        dfs(ans, 0);
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> res = cl.constructDistancedSequence(n);
    for (int i=0; i<2*n-1; ++i) printf("%d%c", res[i], (i<2*n-2?' ':'\n'));
    return 0;
}
