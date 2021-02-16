#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n = S.length();
        vector<int> id;
        for (int i=0; i<n; ++i) if (isalpha(S[i])) id.push_back(i);
        int m = id.size();
        vector<string> ans;
        for (int i=0; i<(1<<m); ++i) {
            string t = S;
            for (int j=0; j<m; ++j) {
                if ((i>>j)&1) t[id[j]] = toupper(t[id[j]]);
                else t[id[j]] = tolower(t[id[j]]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};

int main(){
    return 0;
}
