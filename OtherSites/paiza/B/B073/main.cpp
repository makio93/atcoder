#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        int s, e;
        cin >> s >> e;
        --s;
        int sum = 0;
        for (int j=s; j<e; ++j) sum += a[j];
        int add = m - sum / (e-s);
        if (add > 0) {
            for (int j=s; j<e; ++j) a[j] += add;
        }
    }
    for (int i=0; i<n; ++i) printf("%d%c", a[i], (i<n-1?' ':'\n'));
    return 0;
}
