#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> d(5);
    for (int i=0; i<5; ++i) cin >> d[i];
    for (int i=1; i<5; ++i) cout << (d[i]-d[i-1]) << endl;
    return 0;
}
