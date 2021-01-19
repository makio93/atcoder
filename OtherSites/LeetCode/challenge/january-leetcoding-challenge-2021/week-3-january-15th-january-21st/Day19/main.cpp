#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        pair<int, pair<int, int>> mlen = { 1, { 0, 0 } };
        for (int i=0; i<n; ++i) {
            int l = i-1, r = i+1;
            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    if (r-l+1 > mlen.first) mlen = max(mlen, { r-l+1, { l, r } });
                    --l; ++r;
                }
                else break;
            }
            l = i, r = i+1;
            while (l>=0 && r<n) {
                if (s[l] == s[r]) {
                    if (r-l+1 > mlen.first) mlen = max(mlen, { r-l+1, { l, r } });
                    --l; ++r;
                }
                else break;
            }
        }
        return s.substr(mlen.second.first, mlen.first);
    }
};

int main(){
    
    return 0;
}
