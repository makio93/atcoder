#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), pos = -1;
        const int mlim = (int)(1e9);
        vector<int> ans(n, mlim);
        for (int i=0; i<n; ++i) {
            if (s[i] == c) pos = i;
            if (pos != -1) ans[i] = min(ans[i], abs(i-pos));
        }
        pos = -1;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == c) pos = i;
            if (pos != -1) ans[i] = min(ans[i], abs(i-pos));
        }
        return ans;
    }
};

int main(){
    return 0;
}
