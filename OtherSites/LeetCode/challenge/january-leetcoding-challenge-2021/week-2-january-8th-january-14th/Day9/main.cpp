#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), tar = -1, slen = beginWord.size();
        for (int i=0; i<n; ++i) if (wordList[i] == endWord) tar = i;
        if (tar == -1) return 0;
        queue<int> que;
        vector<int> dist(n, (int)(1e9));
        for (int i=0; i<n; ++i) {
            int dif = 0;
            for (int j=0; j<slen; ++j) if (beginWord[j] != wordList[i][j]) ++dif;
            if (dif == 1) {
                que.push(i);
                dist[i] = 2;
            }
        }
        while (!que.empty()) {
            int id = que.front(); que.pop();
            int d = dist[id], nd = d + 1;
            for (int i=0; i<n; ++i) {
                if (i == id) continue;
                if (dist[i] <= nd) continue;
                int dif = 0;
                for (int j=0; j<slen; ++j) if (wordList[id][j] != wordList[i][j]) ++dif;
                if (dif == 1) {
                    que.push(i);
                    dist[i] = nd;
                }
            }
        }
        if (dist[tar] == (int)(1e9)) return 0;
        else return dist[tar];
    }
};

int main(){
    
    return 0;
}
