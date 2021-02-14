#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        const long long mod = (long long)(1e9) + 7;
        int n = s.length();
        vector<pair<char, int>> run;
        run.emplace_back(s.front(), 1);
        for (int i=1; i<n; ++i) {
            if (s[i] == run.back().first) run.back().second++;
            else run.emplace_back(s[i], 1);
        }
        long long cnt = 0;
        for (int i=0; i<(int)(run.size()); ++i) {
            cnt = (cnt + (long long)(run[i].second)*(run[i].second+1) / 2) % mod;
        }
        return cnt;
    }
};

int main(){
    return 0;
}
