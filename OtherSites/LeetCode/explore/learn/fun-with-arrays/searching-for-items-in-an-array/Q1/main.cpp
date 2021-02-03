#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        bool ok = false;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            if (arr[i]*2==arr[j] || arr[j]*2==arr[i]) ok = true;
        }
        return ok;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    if (cl.checkIfExist(arr)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
