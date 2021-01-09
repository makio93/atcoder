#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), l = -1, ans = 0;
        vector<int> cnt(128, 0);
        for (int i=0; i<n; ++i) {
            cnt[(int)(s[i])]++;
            while (cnt[(int)(s[i])] > 1) {
                ++l;
                cnt[(int)(s[l])]--;
            }
            ans = max(ans, i-l);
        }
        return ans;
    }
};

int main(){
    return 0;
}
