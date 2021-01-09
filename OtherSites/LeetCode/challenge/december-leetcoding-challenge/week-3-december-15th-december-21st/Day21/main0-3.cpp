#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if (n <= 1) return 0;
        sort(A.begin(), A.end());
        for (int i=0; i<n; ++i) A[i] += K;
        int mnval = A[0], mxval = A[n-1], mxval2 = A[n-1]-K*2, sub = mxval - mnval;
        for (int i=n-1; i>=1; --i) {
            mxval = max(A[i-1], mxval2);
            mnval = min(mnval, A[i]-K*2);
            sub = min(sub, mxval-mnval);
        }
        return sub;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    cin >> k;
    int res = cl.smallestRangeII(a, k);
    cout << res << endl;
    return 0;
}
