#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long mod = (1e9+7);
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for (int i=1; i<=n; ++i) {
            long long tnum = i;
            while (tnum > 0) {
                ans = ans * 2 % mod;
                tnum /= 2;
            }
            ans += i;
        }
        return (int)(ans);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    cout << cl.concatenatedBinary(n) << endl;
    return 0;
}
