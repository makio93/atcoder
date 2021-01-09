#include <bits/stdc++.h>
using namespace std;

string si;
int xi, yi;
int search(int p, int len) {
    if (p+1 >= (int)(s.size())) return 0;
    if (s[p]!='a' && s[p]!='b') return 0;
    if (s[p+1]!='a' && s[p+1]!='b') return 0;
    return res;
}

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        si = s; xi = x; yi = y;
        bool area = false;
        for (int i=0; i<n; ++i) {
            if (s[i]=='a' || s[i]=='b') {
                if (!area) {
                    ans += search(i, s, x, y);
                    area = true;
                }
            }
            else {
                if (area) area = false;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
