#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n+1);
    f[0] = 1;
    for (int i=1; i<=n; ++i) cin >> f[i];
    int ans = 0;
    for (int i=0; i<n; ++i) ans += abs(f[i+1]-f[i]);
    cout << ans << endl;
    return 0;
}
