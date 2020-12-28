#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i=0; i<h; ++i) cin >> c[i];
    pair<int, pair<int, int>> ans = { (int)(1e9), { 0, 0 } };
    for (int i=1; i<h; ++i) for (int j=1; j<w; ++j) {
        vector<int> cnt(4);
        for (int i2=0; i2<h; ++i2) for (int j2=0; j2<w; ++j2) {
            int p = 0;
            if (i2>=i) p |= 1<<1;
            if (j2>=j) p |= 1;
            if (c[i2][j2] == '@') cnt[p]++;
        }
        vector<int> val(4);
        for (int i2=0; i2<4; ++i2) {
            int area = 1;
            if ((i2>>1)&1) area *= h - i;
            else area *= i;
            if (i2&1) area *= w - j;
            else area *= j;
            val[i2] = area + cnt[i2] * cnt[i2];
        }
        int mxval = 0, mnval = (int)(1e9);
        for (int i2=0; i2<4; ++i2) {
            mxval = max(mxval, val[i2]);
            mnval = min(mnval, val[i2]);
        }
        ans = min(ans, { mxval-mnval, { i, j } });
    }
    int a = ans.second.first, b = ans.second.second;
    cout << a << ' ' << b << endl;
    return 0;
}
