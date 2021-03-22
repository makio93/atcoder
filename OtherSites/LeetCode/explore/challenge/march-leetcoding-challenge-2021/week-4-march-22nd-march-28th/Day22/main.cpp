#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size(), m = queries.size();
        vector<map<string, set<int>>> converter(3);
        for (int i=0; i<n; ++i) converter[0][wordlist[i]].insert(i);
        for (auto itr=converter[0].begin(); itr!=converter[0].end(); ++itr) {
            string tstr = itr->first;
            for (int j=0; j<(int)(itr->first.length()); ++j) tstr[j] = toupper(tstr.c_str()[j]);
            for (auto itr2=itr->second.begin(); itr2!=itr->second.end(); ++itr2) converter[1][tstr].insert(*itr2);
        }
        const string vowel = "AEIOU";
        for (auto itr=converter[1].begin(); itr!=converter[1].end(); ++itr) {
            string tstr = itr->first;
            for (int j=0; j<(int)(itr->first.length()); ++j) {
                bool isvow = false;
                for (int j2=0; j2<(int)(vowel.size()); ++j2) if (tstr[j] == vowel[j2]) isvow = true;
                if (isvow) tstr[j] = vowel[0];
            }
            for (auto itr2=itr->second.begin(); itr2!=itr->second.end(); ++itr2) converter[2][tstr].insert(*itr2);
        }
        vector<vector<string>> target(3, vector<string>(m));
        for (int i=0; i<m; ++i) target[0][i] = queries[i];
        for (int i=0; i<m; ++i) {
            string tstr = target[0][i];
            for (int j=0; j<(int)(target[0][i].length()); ++j) tstr[j] = toupper(tstr.c_str()[j]);
            target[1][i] = tstr;
        }
        for (int i=0; i<m; ++i) {
            string tstr = target[1][i];
            for (int j=0; j<(int)(target[1][i].length()); ++j) {
                bool isvow = false;
                for (int j2=0; j2<(int)(vowel.size()); ++j2) if (tstr[j] == vowel[j2]) isvow = true;
                if (isvow) tstr[j] = vowel[0];
            }
            target[2][i] = tstr;
        }
        vector<string> ans(m);
        for (int i=0; i<m; ++i) {
            for (int i2=0; i2<(int)(target.size()); ++i2) {
                if (converter[i2].find(target[i2][i]) != converter[i2].end()) {
                    ans[i] = wordlist[*converter[i2][target[i2][i]].begin()];
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
