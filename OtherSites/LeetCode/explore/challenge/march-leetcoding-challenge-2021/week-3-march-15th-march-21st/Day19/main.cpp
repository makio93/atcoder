#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> que;
        vector<bool> visited(n);
        que.push(0);
        visited[0] = true;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (int i=0; i<(int)(rooms[v].size()); ++i) {
                int to = rooms[v][i];
                if (visited[to]) continue;
                que.push(to);
                visited[to] = true;
            }
        }
        bool ans = true;
        for (int i=0; i<n; ++i) if (!visited[i]) ans = false;
        return ans;
    }
};

int main(){
    return 0;
}
