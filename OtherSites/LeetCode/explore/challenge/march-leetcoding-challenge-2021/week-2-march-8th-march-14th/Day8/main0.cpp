#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        if (n <= 1) return n;
        int l = 0, r = n-1, res = 0;
        if (s[l] != s[r]) {
            while (l<r && s[l]!=s[r]) { --r; }
            ++res;
            if (l == r) return res + 1;
        }
        while (l < r) {
            while (l<r && s[l]==s[r] && s[l+1]==s[r-1]) { ++l; --r; }
            while (l<r && s[l]==s[r] && s[l+1]!=s[r-1]) {
                if (s[l+1] == s[r]) ++l;
                else if (s[r-1] == s[l]) --r;
            }
            ++res;
        }
        return res;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    cout << cl.removePalindromeSub(s) << endl;
    return 0;
}
