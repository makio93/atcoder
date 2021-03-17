#include <bits/stdc++.h>
using namespace std;

class Solution {
    double l, t, x, y, r, s;
    mt19937* pmt;
public:
    Solution(double radius, double x_center, double y_center) {
        pmt = new mt19937((int)time(NULL));
        x = x_center; y = y_center; r = radius;
        l = x_center - radius; t = y_center - radius; s = radius * 2;
    }
    
    vector<double> randPoint() {
        vector<double> res(2);
        do {
            res = { l+(double)(*pmt)()/(double)(1LL<<32)*s, t+(double)(*pmt)()/(double)(1LL<<32)*s };
        } while (fabs(res[0]-x)*fabs(res[0]-x)+fabs(res[1]-y)*fabs(res[1]-y)>r*r);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main(){
    return 0;
}
