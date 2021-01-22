#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        if (n != (int)(word2.size())) return false;
        vector<int> cnt1(26), cnt2(26);
        for (int i=0; i<n; ++i) {
            cnt1[word1[i]-'a']++;
            cnt2[word2[i]-'a']++;
        }
        for (int i=0; i<26; ++i) if ((bool)(cnt1[i]) xor (bool)(cnt2[i])) return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for (int i=0; i<26; ++i) if (cnt1[i] != cnt2[i]) return false;
        return true;
    }
};

int main(){
    Solution cl;
    string word1, word2;
    cin >> word1 >> word2;
    if (cl.closeStrings(word1, word2)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
