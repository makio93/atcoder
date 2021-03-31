#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct BIT {
        int n;
        vector<int> bit;
        BIT(int n_) : n(n_), bit(n_+1) {}
        int query(int i) {
            int s = 0;
            while (i > 0) {
                s = max(s, bit[i]);
                i -= i & -i;
            }
            return s;
        }
        void add(int i, int x) {
            while (i <= n) {
                bit[i] = max(bit[i], x);
                i += i & -i;
            }
        }
    };
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        envelopes.erase(unique(envelopes.begin(), envelopes.end()), envelopes.end());
        int n = envelopes.size();
        BIT hval((int)(1e4+1));
        vector<pair<int, int>> hstock;
        for (int i=0; i<n; ++i) {
            int hmax = hval.query(envelopes[i][1]-1);
            hstock.emplace_back(envelopes[i][1], hmax+1);
            if (i+1>=n || envelopes[i][0]!=envelopes[i+1][0]) {
                for (int j=0; j<(int)(hstock.size()); ++j) hval.add(hstock[j].first, hstock[j].second);
                hstock.clear();
            }
        }
        return hval.query((int)(1e4));
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<vector<int>> envelopes(n, vector<int>(2));
    for (int i=0; i<n; ++i) cin >> envelopes[i][0] >> envelopes[i][1];
    cout << cl.maxEnvelopes(envelopes) << endl;
    return 0;
}
