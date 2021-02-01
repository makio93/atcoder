#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        for (int i=0; i<n; ++i) {
            if (arr[i] == 0) {
                arr.insert(arr.begin()+(i+1), 0);
                arr.pop_back();
                ++i;
            }
        }
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    cl.duplicateZeros(arr);
    for (int i=0; i<n; ++i) printf("%d%c", arr[i], (i<n-1?' ':'\n'));
    return 0;
}
