#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        vector<int> sub(n-1);
        for (int i=0; i<n-1; ++i) sub[i] = arr[i+1] - arr[i];
        int l = -1, r = n-1;
        for (int i=0; i<n-1; ++i) {
            if (sub[i] > 0) l = i;
            else break;
        }
        for (int i=n-2; i>=0; --i) {
            if (sub[i] < 0) r = i;
            else break;
        }
        return (l!=-1 && r!=n-1 && l+1==r);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    if (cl.validMountainArray(arr)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
