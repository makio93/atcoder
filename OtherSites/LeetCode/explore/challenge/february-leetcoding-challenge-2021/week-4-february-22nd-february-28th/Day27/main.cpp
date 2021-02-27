#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dividend2 = dividend, divisor2 = divisor;
        if (divisor2 < 0) {
            dividend2 = -dividend2;
            divisor2 = -divisor2;
        }
        bool neg = (dividend2 < 0LL);
        if (neg) dividend2 = -dividend2;
        long long res = 0LL;
        for (int i=31; i>=0; --i) {
            long long sub = divisor2<<i;
            while (dividend2 - sub >= 0) {
                dividend2 -= sub;
                res += 1LL<<i;
            }
        }
        if (neg) res = -res;
        if (res<(-(1LL<<31)) || res>(1LL<<31)-1) res = (1LL<<31)-1;
        return (int)(res);
    }
};

int main(){
    Solution cl;
    int dividend, divisor;
    cin >> dividend >> divisor;
    cout << cl.divide(dividend, divisor) << endl;
    return 0;
}
