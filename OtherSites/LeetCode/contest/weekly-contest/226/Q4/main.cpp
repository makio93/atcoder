#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> memo(n+1, vector<bool>(n+1));
        for (int i=0; i<n; ++i) {
            int l = i, r = i+1;
            while (l>=0 && r<=n) {
                if (s[l] == s[r-1]) memo[l][r] = true;
                else break;
                --l; ++r;
            }
            l = i; r = i+2;
            while (l>=0 && r<=n) {
                if (s[l] == s[r-1]) memo[l][r] = true;
                else break;
                --l; ++r;
            }
        }
        bool ans = false;
        for (int i=1; i<n-1; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (memo[0][i] && memo[i][j] && memo[j][n]) ans = true;
                if (ans) break;
            }
            if (ans) break;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    if (cl.checkPartitioning(s)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
