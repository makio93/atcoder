#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> ver, hor;
    for (int i=0; i<n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) ver.emplace_back(a, make_pair(b, d));
        else if (b == d) hor.emplace_back(b, make_pair(a, c));
    }
    sort(ver.begin(), ver.end()); sort(hor.begin(), hor.end());
    int ans = 1e9;
    for (int i=0; i<(int)(ver.size())-1; ++i) {
        for (int i2=i+1; i2<(int)(ver.size()); ++i2){
            int brd = ver[i2].first - ver[i].first;
            int up = max(ver[i].second.first, ver[i2].second.first), down = min(ver[i].second.second, ver[i2].second.second);
            for (int j=0; j<(int)(hor.size())-1; ++j) {
                if (hor[j].first<up || hor[j].first>down) continue;
                int l = hor[j].second.first, r = hor[j].second.second;
                if (l>ver[i].first || r<ver[i2].first) continue;
                for (int j2=j+1; j2<int(hor.size()); ++j2) {
                    if (hor[j2].first<up || hor[j2].first>down) continue;
                    int l2 = hor[j2].second.first, r2 = hor[j2].second.second;
                    if (l2>ver[i].first || r2<ver[i2].first) continue;
                    ans = min(ans, brd*(hor[j2].first-hor[j].first));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
