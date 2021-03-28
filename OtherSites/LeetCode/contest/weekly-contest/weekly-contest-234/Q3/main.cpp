#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length(), m = knowledge.size();
        map<string, string> dict;
        for (int i=0; i<m; ++i) dict[knowledge[i][0]] = knowledge[i][1];
        string res, word;
        bool inword = false;
        for (int i=0; i<n; ++i) {
            if (inword) {
                if (s[i] == ')') {
                    if (dict.find(word) != dict.end()) res += dict[word];
                    else res += "?";
                    word = "";
                    inword = false;
                }
                else word += s[i];
            }
            else {
                if (s[i] == '(') inword = true;
                else res += s[i];
            }
        }
        return res;
    }
};

int main(){
    return 0;
}
