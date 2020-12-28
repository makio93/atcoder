#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long p = 0;
        int now = 1;
        while (!(p-target>=0 && (p-target)%2==0)) {
            p += now;
            ++now;
        }
        return now-1;
    }
};

int main() {
    Solution cl;
    int target;
    cin >> target;
    int res = cl.reachNumber(target);
    cout << res << endl;
    return 0;
}
