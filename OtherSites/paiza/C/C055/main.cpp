#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string g;
    cin >> g;
    int glen = g.size();
    vector<string> s(n);
    for (int i=0; i<n; ++i) cin >> s[i];
    vector<string> ans;
    for (int i=0; i<n; ++i) {
        int len = s[i].size();
        for (int j=0; j+glen-1<len; ++j) {
            if (g == s[i].substr(j, glen)) {
                ans.push_back(s[i]);
                break;
            }
        }
    }
    if (!ans.empty()) for (string a : ans) cout << a << endl;
    else cout << "None" << endl;
    return 0;
}
