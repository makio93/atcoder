#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
set<int> st;
bool dfs(int d) {
    if (d == (int)(ans.size())) return true;
    if (st.empty()) return true;
    if (ans[d] != 0) return dfs(d+1);
    for (auto itr=st.begin(); itr!=st.end(); ++itr) {
        if (-(*itr) == 1) {
            ans[d] = 1;
            st.erase(-1);
            if (dfs(d+1)) return true;
            st.insert(-1);
            ans[d] = 0;
        }
        else {
            int id = d + -(*itr);
            if (id >= (int)(ans.size())) continue;
            if (ans[id] != 0) continue;
            ans[d] = ans[id] = -(*itr);
            st.erase(*itr);
            if (dfs(d+1)) return true;
            st.insert(*itr);
            ans[d] = ans[id] = 0;
        }
    }
    return false;
}

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        ans = vector<int>(2*n-1);
        for (int i=1; i<=n; ++i) st.insert(-i);
        dfs(0);
        return ans;
    }
};

int main(){
    return 0;
}
