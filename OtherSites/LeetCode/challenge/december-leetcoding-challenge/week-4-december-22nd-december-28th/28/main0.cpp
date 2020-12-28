#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int mxdist = abs(target);
        queue<int> q;
        map<int, int> dist;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int d = dist[v], nd = d + 1;
            if (v+nd <= mxdist) {
                if (dist.find(v+nd) == dist.end()) {
                    q.push(v+nd);
                    dist[v+nd] = nd;
                    if (abs(v+nd) == mxdist) break;
                }
            }
            if (d>0 && v-nd>=-mxdist) {
                if (dist.find(v-nd) == dist.end()) {
                    q.push(v-nd);
                    dist[v-nd] = nd;
                    if (abs(v-nd) == mxdist) break;
                }
            }
        }
        int res = (int)(1e9);
        if (dist.find(target) != dist.end()) res = min(res, dist[target]);
        if (dist.find(-target) != dist.end()) res = min(res, dist[-target]);
        return res;
    }
};

int main() {
    Solution cl;
    int target;
    cin >> target;
    int res = cl.reachNumber(target);
    cout << res << endl;
    return 0;
}
