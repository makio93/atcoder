#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if (n <= 1) return 0;
        sort(A.begin(), A.end());
        for (int i=0; i<n; ++i) A[i] += K;
        int ans = A[n-1] - A[0];
        for (int i=0; i<n-1; ++i) {
            ans = min(ans, max(A[i],A[n-1]-2*K)-min(A[i+1]-2*K,A[0]));
        }
        return ans;
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
