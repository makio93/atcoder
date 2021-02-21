#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (Y<=X) return abs(X-Y);
        else {
            if (Y%2==0) return brokenCalc(X,Y/2)+1;
            else return brokenCalc(X,Y+1)+1;
        }
    }
};

int main(){
    Solution cl;
    int X, Y;
    cin >> X >> Y;
    cout << cl.brokenCalc(X, Y) << endl;
    return 0;
}
