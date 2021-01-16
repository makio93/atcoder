#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        vector<int> num = { 0, 1 };
        int res = 1;
        for (int i=1; i*2+1<=n; ++i) {
            num.push_back(num[i]);
            res = max(res, num.back());
            if ((int)(num.size()) == n+1) break;
            num.push_back(num[i]+num[i+1]);
            res = max(res, num.back());
        }
        return res;
    }
};

int main(){
    
    return 0;
}
