#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int m = d.size();
        pair<int, string> mval = { 0, "" };
        for (int i=0; i<m; ++i) {
            int len = d[i].length();
            unsigned int l = 0;
            bool ok = true;
            for (int j=0; j<len; ++j) {
                size_t ipos = s.find(d[i][j], l);
                if (ipos == string::npos) {
                    ok = false;
                    break;
                }
                l = ipos + 1;
            }
            if (ok) mval = min(mval, {-len,d[i]});
        }
        return mval.second;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> d(n);
    for (int i=0; i<n; ++i) cin >> d[i];
    cout << cl.findLongestWord(s, d) << endl;
    return 0;
}
