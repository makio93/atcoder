#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        map<int, int> cnt;
        for (int i=lowLimit; i<=highLimit; ++i) {
            int num = 0, t = i;
            while (t > 0) {
                num += t % 10;
                t /= 10;
            }
            cnt[num]++;
        }
        int ans = 0;
        for (auto p : cnt) ans = max(ans, p.second);
        return ans;
    }
};

int main(){
    Solution cl;
    int lowLimit, highLimit;
    cin >> lowLimit >> highLimit;
    cout << cl.countBalls(lowLimit, highLimit) << endl;
    return 0;
}
