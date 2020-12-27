#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i] >> d[i];
    long long p1 = (long long)(1e18), p2 = 0LL;
    for (int i=0; i<n; ++i) {
        long long cost = b[i];
        int xi = x - a[i];
        if (xi >= 0) cost += (long long)(xi / c[i] + 1) * d[i];
        p1 = min(p1, cost);
        p2 = max(p2, cost);
    }
    cout << p1 << ' ' << p2 << endl;
    return 0;
}
