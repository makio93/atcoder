#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i=1; i<=n; ++i) {
            if (n%i == 0) {
                --k;
                if (k == 0) return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n >> k;
    cout << cl.kthFactor(n, k) << endl;
    return 0;
}
