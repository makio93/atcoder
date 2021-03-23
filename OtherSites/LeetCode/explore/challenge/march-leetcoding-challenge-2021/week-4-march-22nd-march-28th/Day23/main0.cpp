#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long mod = (long long)(1e9) + 7;
        int n = arr.size();
        long long res = 0LL;
        unordered_map<int, long long> vcnt;
        vcnt[arr[0]+arr[1]] = (vcnt[arr[0]+arr[1]] + 1) % mod;
        for (int i=2; i<n; ++i) {
            if (vcnt.find(target-arr[i]) != vcnt.end()) res = (res + vcnt[target-arr[i]]) % mod;
            for (int j=0; j<i; ++j) vcnt[arr[i]+arr[j]] = (vcnt[arr[i]+arr[j]] + 1) % mod;
        }
        return (int)res;
    }
};

int main(){
    return 0;
}
