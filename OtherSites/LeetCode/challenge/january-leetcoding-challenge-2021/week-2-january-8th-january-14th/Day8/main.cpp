#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = (int)(word1.size()), n2 = (int)(word2.size());
        string s1, s2;
        for (int i=0; i<n1; ++i) s1 += word1[i];
        for (int i=0; i<n2; ++i) s2 += word2[i];
        if (s1 == s2) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}
