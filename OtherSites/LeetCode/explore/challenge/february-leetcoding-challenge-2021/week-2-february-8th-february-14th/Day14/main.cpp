#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> search;
    bool dfs(vector<vector<int>>& graph, int v, int p=-1, int d=0) {
        if (search[v] != -1) return (search[v]%2 == d%2);
        search[v] = d;
        for (int i=0; i<(int)(graph[v].size()); ++i) {
            if (graph[v][i] == p) continue;
            if (!dfs(graph, graph[v][i], v, d+1)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        search = vector<int>(n, -1);
        for (int i=0; i<n; ++i) {
            if (search[i] != -1) continue;
            if (!dfs(graph, i)) return false;
        }
        return true;
    }
};

int main(){
    return 0;
}
