#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<pair<int, int>> h2(n);
        for (int i=0; i<n; ++i) h2[i] = { height[i], i+1 };
        sort(h2.rbegin(), h2.rend());
        set<int> ids;
        long long ans = 0LL;
        for (int i=0; i<n; ++i) {
            if (!ids.empty()) {
                auto itr = ids.lower_bound(h2[i].second);
                if (itr == ids.end()) ans = max(ans, (long long)abs(h2[i].second-*ids.begin())*h2[i].first);
                else if (itr == ids.begin()) ans = max(ans, (long long)abs(h2[i].second-*ids.rbegin())*h2[i].first);
            }
            ids.insert(h2[i].second);
        }
        return (int)ans;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i=0; i<n; ++i) cin >> height[i];
    cout << cl.maxArea(height) << endl;
    return 0;
}
