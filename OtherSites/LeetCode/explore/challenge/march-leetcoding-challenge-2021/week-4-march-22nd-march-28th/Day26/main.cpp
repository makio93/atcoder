#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int n = A.size(), m = B.size();
        vector<int> bcnt(26);
        for (int i=0; i<m; ++i) {
            vector<int> tcnt(26);
            for (int j=0; j<(int)(B[i].length()); ++j) tcnt[(int)(B[i][j]-'a')]++;
            for (int j=0; j<26; ++j) bcnt[j] = max(bcnt[j], tcnt[j]);
        }
        vector<string> res;
        for (int i=0; i<n; ++i) {
            vector<int> tcnt(26);
            for (int j=0; j<(int)(A[i].length()); ++j) tcnt[(int)(A[i][j]-'a')]++;
            bool ok = true;
            for (int j=0; j<26; ++j) if (tcnt[j] < bcnt[j]) ok = false;
            if (ok) res.push_back(A[i]);
        }
        return res;
    }
};

int main(){
    Solution cl;
    
    return 0;
}
