#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> que;
        for (int i=0; i<n; ++i) {
            if (classes[i][0] == classes[i][1]) que.emplace(0.0, i);
            else {
                double sub = (double)(classes[i][0]+1)/(classes[i][1]+1) - (double)(classes[i][0])/classes[i][1];
                que.emplace(sub, i);
            }
        }
        vector<int> add(n);
        for (int i=0; i<extraStudents; ++i) {
            auto p = que.top(); que.pop();
            add[p.second]++;
            double sub = (double)(classes[p.second][0]+add[p.second]+1)/(classes[p.second][1]+add[p.second]+1) - (double)(classes[p.second][0]+add[p.second])/(classes[p.second][1]+add[p.second]);
            que.emplace(sub, p.second);
        }
        vector<double> ave(n);
        for (int i=0; i<n; ++i) {
            if (classes[i][0] == classes[i][1]) ave[i] = 1.0;
            else ave[i] = (double)(classes[i][0]+add[i]) / (classes[i][1]+add[i]);
        }
        double sum = 0.0;
        for (int i=0; i<n; ++i) sum += ave[i];
        return (sum / (double)n);
    }
};

int main(){
    return 0;
}
