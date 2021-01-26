#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        for (int i=0; i<(1<<(n-1)); ++i) {
            vector<string> slst;
            int pre = 0;
            for (int j=0; j<n-1; ++j) if ((i>>j)&1) {
                slst.push_back(s.substr(pre, (j+1)-pre));
                pre = j+1;
            }
            slst.push_back(s.substr(pre, n-pre));
            bool ok = true;
            for (int j=0; j<(int)(slst.size()); ++j) {
                int m = slst[j].size(), l = 0, r = m-1;
                while (r >= l) {
                    if (slst[j][l] != slst[j][r]) ok = false;
                    ++l; --r;
                }
            }
            if (ok) res.push_back(slst);
        }
        return res;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    auto res = cl.partition(s);
    for (int i=0; i<(int)(res.size()); ++i) {
        int m = res[i].size();
        for (int j=0; j<m; ++j) printf("%s%c", res[i][j].c_str(), (char)((j<m-1)?' ':'\n'));
    }
    return 0;
}
