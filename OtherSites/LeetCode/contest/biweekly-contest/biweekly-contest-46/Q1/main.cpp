#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        vector<pair<int, int>> ccnt(26);
        for (int i=0; i<n; ++i) {
            if (islower(s[i])) ccnt[s[i]-'a'].second++;
            else ccnt[s[i]-'A'].first++;
        }
        int ans = 0;
        string res = "";
        for (int i=0; i<n; ++i) {
            auto tcnt = ccnt;
            bool ok = true;
            for (int j=0; j<26; ++j) if ((tcnt[j].first>0) xor (tcnt[j].second>0)) ok = false;
            if (ok) {
                if (ans < n-i) {
                    ans = n-i;
                    res = s.substr(i);
                }
            }
            else {
                for (int j=n-1; j>i; --j) {
                    if (islower(s[j])) tcnt[s[j]-'a'].second--;
                    else tcnt[s[j]-'A'].first--;
                    bool ok2 = true;
                    for (int j2=0; j2<26; ++j2) if ((tcnt[j2].first>0) xor (tcnt[j2].second>0)) ok2 = false;
                    if (ok2) {
                        if (ans < j-i) {
                            ans = j-i;
                            res = s.substr(i,j-i);
                        }
                        break;
                    }
                }
            }
            if (islower(s[i])) ccnt[s[i]-'a'].second--;
            else ccnt[s[i]-'A'].first--;
        }
        return res;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    cout << cl.longestNiceSubstring(s) << endl;
    return 0;
}
