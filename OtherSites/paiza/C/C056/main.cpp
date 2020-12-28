#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        int score = max(0, a-b*5);
        if (score >= m) cout << (i+1) << endl;
    }
    return 0;
}
