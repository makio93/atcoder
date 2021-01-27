#include <bits/stdc++.h>
using namespace std;

// 自力で提出、WAに

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        list<int> bal;
        bal.push_back(1);
        for (int i=0; i<n; ++i) if (nums[i] != 0) bal.push_back(nums[i]);
        bal.push_back(1);
        long long ans = 0;
        while ((int)(bal.size()) > 2) {
            pair<int, pair<int, long long>> mval = { 0, { -1, 0 } };
            auto itr = next(bal.begin());
            int ni = (int)(bal.size());
            for (int i=1; i<ni-1; ++i,++itr) {
                bool ok = true;
                auto pitr = prev(itr), nitr = next(itr);
                long long vval = (long long)(*pitr) * (*nitr);
                if (i-1>=1) {
                    long long pval = (long long)(*prev(pitr)) * (*next(pitr));
                    if (pval > vval) ok = false;
                }
                if (i+1<ni-1) {
                    long long nval = (long long)(*prev(nitr)) * (*next(nitr));
                    if (nval > vval) ok = false;
                }
                if (ok) mval = max(mval, { vval, { i, vval*(*itr) } });
            }
            ans += mval.second.second;
            bal.erase(next(bal.begin(), mval.second.first));
        }
        return (int)(ans);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    cout << cl.maxCoins(nums) << endl;
    return 0;
}
