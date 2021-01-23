#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        map<int, int> ab, cd;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) ab[A[i]+B[j]]++;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cd[C[i]+D[j]]++;
        int ans = 0;
        for (auto p1 : ab) {
            if (cd.find(-(p1.first)) == cd.end()) continue;
            ans += cd[-(p1.first)] * p1.second;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    for (int i=0; i<n; ++i) cin >> c[i];
    for (int i=0; i<n; ++i) cin >> d[i];
    cout << cl.fourSumCount(a, b, c, d) << endl;
    return 0;
}
