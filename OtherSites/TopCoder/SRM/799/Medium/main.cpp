#include <bits/stdc++.h>
using namespace std;

class PlanningTrips {
public:
    int find(int a, vector<int> num) {
        int n = num.size();
        map<int, long long> cnt;
        for (int i=0; i<n; ++i) cnt[num[i]]++;
        auto itr=cnt.begin();
        while (itr!=cnt.end()) {
            if (itr->second >= a) {
                cnt[itr->first+1] += itr->second / a;
                itr->second %= a;
            }
            ++itr;
        }
        itr = cnt.begin();
        while (itr!=cnt.end()) {
            if (itr->second == 0) itr = cnt.erase(itr);
            else ++itr;
        }
        int mval = 0;
        for (auto p : cnt) mval = max(mval, p.first);
        if ((int)(cnt.size()) > 1) ++mval;
        return mval;
    }
};

int main(){
    return 0;
}
