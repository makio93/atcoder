#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int> acnt(26), bcnt(26);
        for (int i=0; i<n; ++i) acnt[a[i]-'a']++;
        for (int i=0; i<m; ++i) bcnt[b[i]-'a']++;
        vector<int> lasum(27), rasum(28), lbsum(27), rbsum(28);
        for (int i=0; i<26; ++i) {
            lasum[i+1] = lasum[i] + acnt[i];
            lbsum[i+1] = lbsum[i] + bcnt[i];
        }
        for (int i=25; i>=0; --i) {
            rasum[i+1] = rasum[i+2] + acnt[i];
            rbsum[i+1] = rbsum[i+2] + bcnt[i];
        }
        int res = max(n, m);
        for (int i=1; i<=25; ++i) {
            res = min(res, lasum[i]+rbsum[i+1]);
            res = min(res, rasum[i+1]+lbsum[i]);
        }
        int acmax = 0, bcmax = 0;
        for (int i=0; i<26; ++i) {
            acmax = max(acmax, acnt[i]);
            bcmax = max(bcmax, bcnt[i]);
        }
        res = min(res, (n-acmax)+(m-bcmax));
        return res;
    }
};

int main(){
    return 0;
}
