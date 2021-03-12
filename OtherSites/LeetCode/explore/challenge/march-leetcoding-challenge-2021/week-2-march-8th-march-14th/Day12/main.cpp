#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        map<string, int> binary;
        for (int i=0; i+k-1<n; ++i) binary[s.substr(i, k)]++;
        return ((int)(binary.size()) == (1<<k));
    }
};

int main(){
    Solution cl;
    string s;
    int k;
    cin >> s >> k;
    if (cl.hasAllCodes(s, k)) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}
