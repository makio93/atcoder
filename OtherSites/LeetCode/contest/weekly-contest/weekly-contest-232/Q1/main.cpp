#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        if (s1 == s2) return true;
        vector<int> diff;
        for (int i=0; i<n; ++i) if (s1[i] != s2[i]) diff.push_back(i);
        if ((int)(diff.size()) != 2) return false;
        if (s2[diff[1]]==s1[diff[0]] && s2[diff[0]]==s1[diff[1]]) return true;
        else return false;
    }
};

int main(){
    return 0;
}
