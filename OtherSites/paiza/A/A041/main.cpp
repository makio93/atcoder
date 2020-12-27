#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), w(n), h(n), s(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> y[i] >> w[i] >> h[i] >> s[i];
    set<int> take;
    for (int i=0; i<n; ++i) if (s[i] == 1) {
        take.insert(i);
        for (int j=i+1; j<n; ++j) {
            bool exist = true;
            if (x[i] >= x[j]+w[j]) exist = false;
            if (x[j] >= x[i]+w[i]) exist = false;
            if (y[i] >= y[j]+h[j]) exist = false;
            if (y[j] >= y[i]+h[i]) exist = false;
            if (exist) {
                take.insert(j);
                s[j] = 1;
            }
        }
    }
    cout << (int)(take.size()) << endl;
    return 0;
}
