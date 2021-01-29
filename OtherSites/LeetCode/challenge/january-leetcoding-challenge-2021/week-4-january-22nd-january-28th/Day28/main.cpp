#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        int l = 0, r = n-1;
        k -= n-1;
        for (int i=n-1; i>=0; --i) {
            if (k>=1 && k<26) {
                l = i; r = n-(i+1);
                break;
            }
            if (i-1>=0) k -= 25;
        }
        string ans = string(l, 'a') + string(1, (char)('a'+k-1)) + string(r, 'z');
        return ans;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n >> k;
    cout << cl.getSmallestString(n, k) << endl;
    return 0;
}
