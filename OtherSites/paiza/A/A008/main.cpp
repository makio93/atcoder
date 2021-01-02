#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(m);
    for (int i=0; i<m; ++i) {
        cin >> d[i];
        d[i]--;
    }
    vector<int> mapping(n);
    int cnt = 0, l = 0, ans = m;
    for (int r=0; r<m; ++r) {
        int ri = d[r];
        if (mapping[ri] == 0) ++cnt;
        mapping[ri]++;
        while (r-l+1>0 && cnt==n) {
            ans = min(ans, r-l+1);
            int li = d[l];
            if (mapping[li] == 1) --cnt;
            mapping[li]--;
            ++l;
        }
    }
    cout << ans << endl;
    return 0;
}
