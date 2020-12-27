#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> n(q);
    for (int i=0; i<q; ++i) cin >> n[i];
    for (int i=0; i<q; ++i) {
        int sum = 0;
        for (int j=1; j<n[i]; ++j) if (n[i]%j==0) sum += j;
        if (sum == n[i]) cout << "perfect" << endl;
        else if (abs(sum-n[i]) == 1) cout << "nearly" << endl;
        else cout << "neither" << endl;
    }
    return 0;
}
