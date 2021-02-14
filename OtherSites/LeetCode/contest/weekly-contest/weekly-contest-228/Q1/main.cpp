#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length(), mval = n, cnt = 0;
        for (int i=0; i<n; ++i) if (s[i] == (char)((i%2)+'0')) ++cnt;
        mval = min(mval, cnt);
        cnt = 0;
        for (int i=0; i<n; ++i) if (s[i] == (char)((1-i%2)+'0')) ++cnt;
        mval = min(mval, cnt);
        return mval;
    }
};

int main(){
    return 0;
}
