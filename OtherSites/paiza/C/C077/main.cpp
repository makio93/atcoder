#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> d(k), a(k);
    for (int i=0; i<k; ++i) cin >> d[i] >> a[i];
    for (int i=0; i<k; ++i) {
        int score = 100 / n * a[i];
        if (d[i] >= 10) score = 0;
        else if (d[i] > 0) score = score * 8 / 10;
        if (score >= 80) cout << "A" << endl;
        else if (score >= 70) cout << "B" << endl;
        else if (score >= 60) cout << "C" << endl;
        else cout << "D" << endl;
    }
    return 0;
}
