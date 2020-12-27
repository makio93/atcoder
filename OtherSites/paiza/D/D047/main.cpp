#include <bits/stdc++.h>
using namespace std;

const vector<string> M = { "Gold", "Silver", "Bronze" };

int main() {
    vector<string> n(3);
    for (int i=0; i<3; ++i) cin >> n[i];
    for (int i=0; i<3; ++i) cout << M[i] << ' ' << n[i] << endl;
    return 0;
}
