#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int, int>> selectedList(n);
        for (int i=0; i<n; ++i) selectedList[i] = { boxTypes[i][1], boxTypes[i][0] };
        sort(selectedList.rbegin(), selectedList.rend());
        int res = 0;
        for (int i=0; i<n; ++i) {
            int taked = min(selectedList[i].second, truckSize);
            res += taked * selectedList[i].first;
            truckSize -= taked;
            if (truckSize <= 0) break;
        }
        return res;
    }
};

int main(){
    return 0;
}
