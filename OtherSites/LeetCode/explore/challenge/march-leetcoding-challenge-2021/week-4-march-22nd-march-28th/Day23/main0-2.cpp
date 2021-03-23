#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long mod = (long long)(1e9) + 7;
        int n = arr.size();
        long long res = 0LL;
        vector<long long> vcnt(101);
        for (int i=0; i<n; ++i) vcnt[arr[i]]++;
        for (int i=0; i<=100; ++i) for (int j=i; j<=100; ++j) {
            int k = target - i - j;
            if (k >= j) {
                if (k>=0 && k<=100) {
                    if (i == j) {
                        if (j == k) res = (res + vcnt[i] * (vcnt[j]-1) * (vcnt[k]-2) / 6) % mod;
                        else res = (res + vcnt[i] * (vcnt[j] - 1) / 2 * vcnt[k]) % mod;
                    }
                    else {
                        if (j == k) res = (res + vcnt[i] * vcnt[j] * (vcnt[j] - 1) / 2) % mod;
                        else res = (res + vcnt[i] * vcnt[j] * vcnt[k]) % mod;
                    }
                }
            }
        }
        return (int)res;
    }
};

int main(){
    Solution cl;
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    cin >> target;
    cout << cl.threeSumMulti(arr, target) << endl;
    return 0;
}
