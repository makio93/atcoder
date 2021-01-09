#include <bits/stdc++.h>
using namespace std;

int search(int p, string& s, int& x, int& y) {
    if (p+1 >= (int)(s.size())) return 0;
    if (s[p]!='a' && s[p]!='b') return 0;
    if (s[p+1]!='a' && s[p+1]!='b') return 0;
    int res = 0;
    if (s.substr(p, 2) == "ab") {
        res += max(x + search(p+2, s, x, y), search(p+1, s, x, y));
    }
    else if (s.substr(p, 2) == "ba") {
        res += max(y + search(p+2, s, x, y), search(p+1, s, x, y));
    }
    else res += max(search(p+1, s, x, y), search(p+2, s, x, y));
    return res;
}

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        bool area = false;
        for (int i=0; i<n; ++i) {
            if (s[i]=='a' || s[i]=='b') {
                if (!area) {
                    ans += search(i, s, x, y);
                    area = true;
                }
            }
            else {
                if (area) area = false;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
