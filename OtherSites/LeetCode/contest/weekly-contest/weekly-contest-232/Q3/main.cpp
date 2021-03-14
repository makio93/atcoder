#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> que;
        for (int i=0; i<n; ++i) if (classes[i][0] < classes[i][1]) que.emplace(pair<int,int>{classes[i][1],classes[i][0]}, i);
        if (que.empty()) return 1.0;
        vector<int> add(n);
        for (int i=0; i<extraStudents; ++i) {
            auto p = que.top(); que.pop();
            add[p.second]++;
            que.emplace(pair<int,int>{p.first.first+1,p.first.second+1}, p.second);
        }
        vector<double> ave(n);
        for (int i=0; i<n; ++i) {
            ave[i] = (double)(classes[i][0]+add[i]) / (classes[i][1]+add[i]);
        }
        double sum = 0.0;
        for (int i=0; i<n; ++i) sum += ave[i];
        return (sum / (double)n);
    }
};

int main(){
    return 0;
}
