#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(4);
    for (int i=0; i<4; ++i) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int sum = 0;
    for (int i=0; i<2; ++i) sum += a[i] * 10 + a[i+2];
    cout << sum << endl;
    return 0;
}
