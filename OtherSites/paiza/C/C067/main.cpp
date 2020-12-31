#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    unsigned long long x;
    cin >> n >> x;
    vector<int> k(n);
    for (int i=0; i<n; ++i) {
        cin >> k[i];
        k[i]--;
    }
    for (int i=0; i<n; ++i) {
        int ans = (int)((x>>k[i])&1);
        cout << ans << endl;
    }
    return 0;
}
