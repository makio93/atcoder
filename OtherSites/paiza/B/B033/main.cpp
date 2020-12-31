#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    cin >> w;
    vector<string> c(w);
    for (int i=0; i<w; ++i) cin >> c[i];
    cin >> h;
    vector<vector<string>> r(h, vector<string>(w));
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) cin >> r[i][j];
    vector<int> mlen(w);
    for (int i=0; i<w; ++i) mlen[i] = (int)(c[i].size());
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) mlen[j] = max(mlen[j], (int)(r[i][j].size()));
    for (int i=0; i<w; ++i) {
        string element = " " + c[i] + string((mlen[i]-(int)(c[i].size()))+1, ' ');
        cout << '|' << element;
        if (i==w-1) cout << '|' << endl;
    }
    for (int i=0; i<w; ++i) {
        cout << '|' << string(mlen[i]+2, '-');
        if (i==w-1) cout << '|' << endl;
    }
    for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) {
        string element = " " + r[i][j] + string((mlen[j]-(int)(r[i][j].size()))+1, ' ');
        cout << '|' << element;
        if (j==w-1) cout << '|' << endl;
    }
    return 0;
}
