#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        string ans;
        while ((int)(ans.size()) == 0) {
            long long cnt = 0;
            char pc = 0;
            for (int i=0; i<n; ++i) {
                if (islower(S[i])) {
                    ++cnt;
                    pc = S[i];
                    if (cnt == K) {
                        ans += pc;
                        break;
                    }
                }
                else if (isdigit(S[i])) {
                    if (cnt*(S[i]-'0') >= K) {
                        if (K%cnt == 0) ans += pc;
                        else K %= cnt;
                        break;
                    }
                    else cnt *= (int)(S[i]-'0');
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    int k;
    cin >> k;
    string res = cl.decodeAtIndex(s, k);
    cout << res << endl;
    return 0;
}
