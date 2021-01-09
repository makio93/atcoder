#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, day = n % 7;
        int ans = 7 * (week-1) * week / 2 + week * 28;
        if (day > 0) ans += (1 + day) * day / 2 + day * week;
        return ans;
    }
};

int main(){
    return 0;
}
