#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int xp = -1, a = (input[2]=='+')?1:-1;
    vector<int> d(3, -1);
    vector<int> did = { 0, 4, 8 };
    for (int i=0; i<(int)(did.size()); ++i) {
        if (input[did[i]] == 'x') xp = i;
        else d[i] = input[did[i]] - '0';
    }
    int ans = -1;
    for (int i=0; i<=9; ++i) {
        d[xp] = i;
        int lval = d[0] + d[1] * a, rval = d[2];
        if (lval == rval) ans = i;
    }
    cout << ans << endl;
    return 0;
}
