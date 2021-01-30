#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[min(rectangles[i][0], rectangles[i][1])]++;
        return cnt.rbegin()->second;
    }
};

int main(){

    return 0;
}
