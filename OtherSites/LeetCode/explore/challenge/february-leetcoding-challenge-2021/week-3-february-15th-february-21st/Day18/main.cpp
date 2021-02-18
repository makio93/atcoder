#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return 0;
        vector<int> b;
        for (int i=0; i<n-1; ++i) b.push_back(A[i+1]-A[i]);
        vector<pair<int, int>> len;
        len.emplace_back(b.front(), 1);
        for (int i=1; i<n-1; ++i) {
            if (b[i] == len.back().first) len.back().second++;
            else len.emplace_back(b[i], 1);
        }
        int ans = 0, m = len.size();
        for (int i=0; i<m; ++i) ans += (len[i].second)*(len[i].second-1)/2;
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    cout << cl.numberOfArithmeticSlices(A) << endl;
    return 0;
}
