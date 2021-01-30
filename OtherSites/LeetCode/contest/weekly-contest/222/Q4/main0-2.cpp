#include <bits/stdc++.h>
using namespace std;

// 本番後、自力研究、BITで実装、AC

class Solution {
    struct BIT {
        int n;
        vector<int> bit;
        BIT(int n_) : n(n_), bit(n_+1) {}
        int smax(int i) {
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
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size(), m = arr.size();
        map<int, set<int>> ids;
        for (int i=0; i<m; ++i) ids[arr[i]].insert(i);
        BIT bt(m+1);
        for (int i=0; i<n; ++i) {
            if (ids.find(target[i]) != ids.end()) {
                auto tst = ids[target[i]];
                for (auto itr=tst.rbegin(); itr!=tst.rend(); ++itr) {
                    int nval = bt.smax(*itr);
                    bt.add((*itr)+1, nval+1);
                }
            }
        }
        return (n - bt.smax(m));
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<int> target(n), arr(m);
    for (int i=0; i<n; ++i) cin >> target[i];
    for (int i=0; i<m; ++i) cin >> arr[i];
    int res = cl.minOperations(target, arr);
    cout << res << endl;
    return 0;
}
