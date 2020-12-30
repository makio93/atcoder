#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            int val = s[i] - '0';
            if (val != 0) dp[i+1] += dp[i];
            if (i-1>=0 && s[i-1]!='0') {
                int val2 = stoi(s.substr(i-1, 2));
                if (val2>=1 && val2<=26) dp[i+1] += dp[i-1]; 
            }
        }
        return dp[n];
    }
};

int main() {
    Solution cl;
    string s;
    cin >> s;
    int ret = cl.numDecodings(s);
    cout << ret << endl;
    return 0;
}
