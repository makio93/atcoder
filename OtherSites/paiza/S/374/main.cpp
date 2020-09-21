#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n, k;
    long long c, sum = 0;
    cin >> n >> c >> k;
    vector<pair<int, int>> bp(n);
    for (int i=0; i<n; ++i) cin >> bp[i].first >> bp[i].second;
    sort(bp.rbegin(), bp.rend());
    priority_queue<int> q;
    for (int i=0; i<k; ++i) {
        sum += bp[i].second;
        q.push(bp[i].second);
    }
    int btm = k-1;
    while (sum > c) {
        ++btm;
        int mxcost = q.top(); q.pop();
        sum -= mxcost;
        int nval = min(mxcost, bp[btm].second);
        q.push(nval);
        sum += nval;
    }
    cout << bp[btm].first << endl;
    return 0;
}
