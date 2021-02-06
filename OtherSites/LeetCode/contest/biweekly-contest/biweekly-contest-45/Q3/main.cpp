#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<pair<char,int>> len(1, {s.front(),1});
        for (int i=1; i<(int)(s.size()); ++i) {
            if (s[i] == s[i-1]) len.back().second++;
            else len.emplace_back(s[i], 1);
        }
        int l = 0, r = len.size()-1;
        while (l < r) {
            if (len[l].first == len[r].first) { ++l; --r; }
            else break;
        }
        if (r-l <= 0) {
            if (len[l].second > 1) return 0;
            else return 1;
        }
        int ans = 0;
        for (int i=l; i<=r; ++i) ans += len[i].second;
        return ans;
    }
};

int main(){
    return 0;
}
