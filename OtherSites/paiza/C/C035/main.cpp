#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        char t;
        cin >> t;
        int sum = 0, sum1 = 0, sum2 = 0;
        for (int j=0; j<5; ++j) {
            int scorei;
            cin >> scorei;
            sum += scorei;
            if (j>=1 && j<=2) sum2 += scorei;
            if (j>=3 && j<=4) sum1 += scorei;
        }
        if (sum >= 350) {
            if ((t=='l'&&sum1>=160) || (t=='s'&&sum2>=160)) ++ans; 
        }
    }
    cout << ans << endl;
    return 0;
}
