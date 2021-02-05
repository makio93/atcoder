#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size(), pos = 0;
        while (pos<n && A[pos]%2==0) ++pos;
        for (int i=pos+1; i<n; ++i) {
            if (A[i]%2==0) {
                swap(A[pos], A[i]);
                ++pos;
            }
        }
        return A;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; ++i) cin >> A[i];
    cl.sortArrayByParity(A);
    for (int i=0; i<n; ++i) printf("%d%c", A[i], (i<n-1?' ':'\n'));
    return 0;
}
