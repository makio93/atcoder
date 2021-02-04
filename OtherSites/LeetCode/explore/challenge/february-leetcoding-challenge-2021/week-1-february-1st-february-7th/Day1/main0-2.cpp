#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            if (n&1) ++cnt;
            n >>= 1;
        }
        return cnt;
    }
};

int main(){
    Solution cl;
    uint32_t n;
    cin >> n;
    cout << cl.hammingWeight(n) << endl;
    return 0;
}
