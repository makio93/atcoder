#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        int add = 1;
        for (int i=n-1; i>=0; --i) {
            res.push_back((digits[i]+add)%10);
            add = (digits[i]+add) / 10;
        }
        if (add > 0) res.push_back(add);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> digits(n);
    for (int i=0; i<n; ++i) cin >> digits[i];
    vector<int> ans = cl.plusOne(digits);
    int n2 = ans.size();
    for (int i=0; i<n2; ++i) printf("%d%c", ans[i], (i<n2-1?' ':'\n'));
    return 0;
}
