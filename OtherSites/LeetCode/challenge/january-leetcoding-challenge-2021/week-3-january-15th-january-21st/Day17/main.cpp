#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int res = 1;
        for (int i=1; i<=4; ++i) res *= n + i;
        res /= 24;
        return res;
    }
};

int main(){
    
    return 0;
}
