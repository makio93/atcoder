#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        long long res = 0LL, mod = (long long)((1e9)+7);
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[deliciousness[i]]++;
        for (auto itr=cnt.begin(); itr!=cnt.end(); ++itr) {
            int two = 1, sval = itr->first, snum = itr->second;
            for (int j=0; j<=21; ++j) {
                int target = two - sval;
                if (target > sval) {
                    auto titr = cnt.find(target);
                    if (titr != cnt.end()) res = (res + (long long)snum * (titr->second)) % mod;
                }
                else if (target == sval) {
                    if (snum > 1) res = (res + (long long)(snum) * (snum - 1) / 2) % mod;
                }
                two *= 2;
            }
        }
        return (int)(res);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> deliciousness(n);
    for (int i=0; i<n; ++i) cin >> deliciousness[i];
    int res = cl.countPairs(deliciousness);
    cout << res << endl;
    return 0;
}
