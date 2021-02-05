#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), mval = -1, pmval = -1;
        for (int i=n-1; i>=0; --i) {
            pmval = mval;
            mval = max(mval, arr[i]);
            arr[i] = pmval;
        }
        return arr;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    vector<int> ans = cl.replaceElements(arr);
    for (int i=0; i<n; ++i) printf("%d%c", arr[i], (i<n-1?' ':'\n'));
    return 0;
}
