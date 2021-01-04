#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> c(2);
    cin >> n >> c[0] >> c[1];
    vector<int> p(n);
    for (int i=0; i<n; ++i) cin >> p[i];
    int money = 0, store = 0;
    for (int i=0; i<n-1; ++i) {
        if (p[i] <= c[0]) {
            money -= p[i];
            store++;
        }
        else if (p[i] >= c[1]) {
            money += store * p[i];
            store = 0;
        }
    }
    money += store * p[n-1];
    cout << money << endl;
    return 0;
}
