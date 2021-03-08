#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int l = 0, r = n-1;
        bool ok = true;
        while (l < r) {
            if (s[l] != s[r]) ok = false;
            ++l; --r;
        }
        return (ok?1:2);
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    cout << cl.removePalindromeSub(s) << endl;
    return 0;
}
