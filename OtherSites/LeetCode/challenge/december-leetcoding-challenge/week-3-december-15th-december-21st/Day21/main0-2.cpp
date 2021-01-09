#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int n = A.size();
        if (n <= 1) return 0;
        for (int i=0; i<n; ++i) A[i] += K;
        int dif1 = A[n-1] - A[0];
        bool turn = false;
        for (int i=1; i<n; ++i) {
            if (turn) {
                A[i] -= 2*K;
                continue;
            }
            int dif2 = A[i-1] - (A[i]-2*K);
            if (dif2 < dif1) {
                A[i] -= 2*K;
                turn = true;
            }
        }
        sort(A.begin(), A.end());
        return (A[n-1]-A[0]);
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
