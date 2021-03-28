#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.length();
        vector<string> dlst;
        bool digit = false;
        for (int i=0; i<n; ++i) {
            if (isdigit(word[i])) {
                if (digit) dlst.back() += word[i];
                else {
                    digit = true;
                    dlst.push_back(string(1, word[i]));
                }
            }
            else {
                if (digit) digit = false;
            }
        }
        set<string> dcnt;
        for (int i=0; i<(int)(dlst.size()); ++i) {
            int zid = (int)(dlst[i].length()) - 1;
            for (int j=0; j<(int)(dlst[i].length()); ++j) {
                if (dlst[i][j] != '0') {
                    zid = j;
                    break;
                }
            }
            dcnt.insert(dlst[i].substr(zid));
        }
        return (int)dcnt.size();
    }
};

int main(){
    return 0;
}
