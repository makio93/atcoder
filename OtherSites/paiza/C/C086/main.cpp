#include <bits/stdc++.h>
using namespace std;

const string TAR = "aeiouAEIOU";

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string ans;
    for (int i=0; i<n; ++i) {
        bool hit = false;
        for (char c : TAR) if (s[i] == c) hit = true;
        if (!hit) ans.push_back(s[i]);
    }
    cout << ans << endl;
    return 0;
}
