#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i=0; i<n; ++i) cin >> d[i];
    int ans = 0;
    bool fir = false;
    int now = 0, len = 0;
    for (int i=0; i<7; ++i) if (d[i] == 0) ++now;
    if (now >= 2) {
        len = 7;
        fir = true;
    }
    ans = max(ans, len);
    for (int i=7; i<n; ++i) {
        if (d[i] == 0) ++now;
        if (d[i-7] == 0) --now;
        if (now >= 2) {
            if (!fir) {
                len = 7;
                fir = true;
            }
            else ++len;
        }
        else {
            if (fir) {
                len = 0;
                fir = false;
            }
        }
        ans = max(ans, len);
    }
    cout << ans << endl;
    return 0;
}
