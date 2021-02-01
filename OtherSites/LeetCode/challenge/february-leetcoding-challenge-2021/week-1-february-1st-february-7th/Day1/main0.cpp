#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) { return (int)(__builtin_popcount(n)); }
};

int main(){
    Solution cl;
    uint32_t n;
    cin >> n;
    cout << cl.hammingWeight(n) << endl;
    return 0;
}
