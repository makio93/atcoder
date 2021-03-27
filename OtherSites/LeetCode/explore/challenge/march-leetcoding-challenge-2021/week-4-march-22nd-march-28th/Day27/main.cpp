#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), res = 0;
        if (n == 0) return 0;
        vector<vector<bool>> memo(n, vector<bool>(n));
        for (int r=0; r<n; ++r) for (int l=0; l<=r; ++l) {
            if (r-l+1 <= 1) memo[l][r] = true;
            else {
                if (s[l] == s[r]) {
                    if (r-l-1 == 0) memo[l][r] = true;
                    else {
                        if (memo[l+1][r-1]) memo[l][r] = true;
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) if (memo[i][j]) ++res;
        return res;
    }
};

int main(){
    return 0;
}
