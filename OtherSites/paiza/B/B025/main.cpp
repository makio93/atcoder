#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> r(m);
    for (int i=0; i<m; ++i) {
        cin >> r[i];
        r[i]--;
    }
    vector<int> stat(n);
    for (int i=0; i<m; ++i) stat[r[i]] = 1;
    for (int i1=0; i1<k; ++i1) {
        for (int i=0; i<m; ++i) {
            int p = r[i];
            while (stat[p%n] == 1) ++p;
            stat[r[i]] = 0;
            stat[p%n] = 1;
            r[i] = p%n;
        }
    }
    for (int i=0; i<m; ++i) cout << (r[i]+1) << endl;
    return 0;
}
