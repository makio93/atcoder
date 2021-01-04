#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<string> s(n);
    for (int i=0; i<n; ++i) cin >> s[i];
    for (int i1=1; i1<=k; ++i1) {
        int n2 = n * n;
        vector<string> s2(n2, string(n2, '.'));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            if (s[i][j] == '.') continue;
            for (int i2=0; i2<n; ++i2) for (int j2=0; j2<n; ++j2) {
                s2[i*n+i2][j*n+j2] = s[i2][j2];
            }
        }
        n = n2;
        s = s2;
    }
    for (int i=0; i<n; ++i) cout << s[i] << endl;
    return 0;
}
