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
        int mval = A[0];
        for (int i=n-1; i>=1; --i) {
            int dif1 = (A[i] - A[i-1]), dif2 = mval - (A[i] - 2*K);
            if (dif2 < dif1) {
                A[i] -= 2*K;
                mval = min(mval, A[i]);
            }
            else break;
        }
        sort(A.begin(), A.end());
        return (A[n-1]-A[0]);
    }
};

int main(){
    return 0;
}
