#include <bits/stdc++.h>
using namespace std;

int main() {
    double r;
    cin >> r;
    int ri = (int)(r + 1.0 - 0.000001), cnt = 0;
    for (int i=0; i<=ri; ++i) for (int j=0; j<=ri; ++j) {
        if (r*r > i*i+j*j) ++cnt;
    }
    cout << (cnt*4) << endl;
    return 0;
}
