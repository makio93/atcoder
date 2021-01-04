#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const vector<string> slst = { "Four Card", "Three Card", "Two Pair", "One Pair", "No Pair" };
    for (int i1=0; i1<n; ++i1) {
        string s;
        cin >> s;
        vector<int> cnt(10), ncnt(5);
        for (int i=0; i<4; ++i) cnt[(int)(s[i]-'0')]++;
        for (int i=0; i<10; ++i) if (cnt[i] > 0) ncnt[cnt[i]]++;
        if (ncnt[4] == 1) cout << slst[0] << endl;
        else if (ncnt[3] == 1) cout << slst[1] << endl;
        else if (ncnt[2] == 2) cout << slst[2] << endl;
        else if (ncnt[2] == 1) cout << slst[3] << endl;
        else cout << slst[4] << endl;
    }
    return 0;
}
