#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> a[i][j];
    vector<vector<int>> b(n/k, vector<int>(n/k));
    for (int i=0; i<n/k; ++i) for (int j=0; j<n/k; ++j) {
        for (int i2=0; i2<k; ++i2) for (int j2=0; j2<k; ++j2) {
            b[i][j] += a[i*k+i2][j*k+j2];
        }
        b[i][j] /= k*k;
    }
    for (int i=0; i<n/k; ++i) for (int j=0; j<n/k; ++j) {
        printf("%d%c", b[i][j], (j<(n/k-1)?' ':'\n'));
    }
    return 0;
}
