#include <bits/stdc++.h>
using namespace std;

// コンテスト後に自力研究、よくわからない

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> queries2(m);
        for (int i=0; i<m; ++i) {
            queries2[i].first = queries[i][1];
            queries2[i].second = { queries[i][0], i };
        }
        sort(queries2.begin(), queries2.end());
    }
};

int main(){
    return 0;
}
