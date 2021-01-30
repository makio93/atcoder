#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        bool sub = false, ans = true;
        for (int i=0; i<n-1; ++i) {
            if (arr[i]==arr[i+1]) ans = false;
            else if (sub) {
                if (arr[i+1] > arr[i]) ans = false;
            }
            else {
                if (arr[i+1] < arr[i]) {
                    if (i==0) ans = false;
                    else sub = true;
                }
            }
            if (!ans) break;
        }
        if (!sub) ans = false;
        return ans;
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
