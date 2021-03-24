#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<pair<int, int>> b2(n);
        for (int i=0; i<n; ++i) b2[i] = { B[i], i };
        sort(b2.rbegin(), b2.rend());
        sort(A.rbegin(), A.rend());
        vector<int> ans(n, -1);
        int aid = 0, bid = 0;
        while (bid < n) {
            while (bid<n && b2[bid].first>=A[aid]) ++bid;
            if (bid >= n) break;
            ans[b2[bid].second] = A[aid];
            ++aid; ++bid;
        }
        for (int i=0; i<n; ++i) if (ans[i] == -1) {
            ans[i] = A[aid];
            ++aid;
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    for (int i=0; i<n; ++i) cin >> B[i];
    auto res = cl.advantageCount(A, B);
    for (int i=0; i<n; ++i) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    return 0;
}
