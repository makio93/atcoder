#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n;
    cin >> s >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    int ans = 0;
    for (int i=0; i<(1<<n); ++i) {
        int sum = 0;
        for (int j=0; j<n; ++j) if ((i>>j)&1) sum += v[j];
        if (sum<s || sum==0) continue;
        int mval = 0;
        for (int j=0; j<n; ++j) if ((i>>j)&1) mval = max(mval, sum-v[j]);
        if (mval < s) ++ans;
    }
    cout << ans << endl;
    return 0;
}
