#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int origin = 0, xsum = 0;
        for (int i=1; i<=n+1; ++i) {
            origin ^= i;
        }
        for (int i=1; i<n; i+=2) xsum ^= encoded[i];
        int f = origin ^ xsum;
        vector<int> ans(n+1);
        ans[0] = f;
        for (int i=0; i<n; ++i) {
            ans[i+1] = ans[i] ^ encoded[i];
        }
        return ans;
    }
};

int main(){
    return 0;
}
