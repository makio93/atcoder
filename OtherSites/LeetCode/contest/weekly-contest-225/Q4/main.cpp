#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        int res = 0, d = 1;
        while (n > 0) {
            for (int i=1; i<=d; ++i) {
                if (n > 0) {
                    ++res;
                    n -= i;
                }
                if (n <= 0) break;
            }
            ++d;
        }
        return res;
    }
};

int main(){
    return 0;
}
