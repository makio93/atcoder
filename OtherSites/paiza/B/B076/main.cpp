#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i) cin >> a[i] >> b[i];
    for (int i=0; i<q; ++i) {
        string qi;
        cin >> qi;
        vector<int> c(n);
        for (int j=0; j<n; ++j) cin >> c[j];
        if (qi == "bake") {
            for (int j=0; j<n; ++j) b[j] += c[j];
        }
        else if (qi == "buy") {
            bool ok = true;
            for (int j=0; j<n; ++j) if (b[j] < c[j]) ok = false;
            if (ok) {
                int sum = 0;
                for (int j=0; j<n; ++j) {
                    b[j] -= c[j];
                    sum += a[j] * c[j];
                }
                cout << sum << endl;
            }
            else cout << -1 << endl;
        }
    }
    return 0;
}
