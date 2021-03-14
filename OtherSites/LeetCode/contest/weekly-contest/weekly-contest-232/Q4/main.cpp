#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums[i], i };
        sort(vals.begin(), vals.end());
        set<int> ids;
        ids.insert(-1); ids.insert(n);
        vector<int> stock;
        long long mval = 0;
        for (int i=0; i<n; ++i) {
            auto rid = ids.upper_bound(vals[i].second);
            auto lid = prev(rid);
            if (k>(*lid) && k<(*rid)) mval = max(mval, (long long)(vals[i].first)*((*rid)-(*lid)-1));
            stock.push_back(vals[i].second);
            if (i==n-1 || vals[i+1].first!=vals[i].first) {
                for (int j=0; j<(int)(stock.size()); ++j) ids.insert(stock[j]);
                stock.clear();
            }
        }
        return (int)(mval);
    }
};

int main(){
    return 0;
}
