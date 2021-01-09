#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0]-1 >= k) return k;
        int n = arr.size(), res = -1;
        k -= arr[0]-1;
        for (int i=0; i<n-1; ++i) {
            if (arr[i+1]-arr[i]-1 < k) k -= arr[i+1]-arr[i]-1;
            else {
                res = arr[i] + k;
                break;
            }
        }
        if (res == -1) res = arr[n-1] + k;
        return res;
    }
};

int main(){
    return 0;
}
