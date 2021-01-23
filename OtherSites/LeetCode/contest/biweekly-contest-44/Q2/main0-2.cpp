#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        int cnt = 0;
        for (int i=0; i<(int)(friendships.size()); ++i) {
            vector<bool> lmemo1(n), lmemo2(n);
            for (int j=0; j<(int)(languages[friendships[i][0]-1].size()); ++j) {
                lmemo1[languages[friendships[i][0]-1][j]-1] = true;
            }
            for (int j=0; j<(int)(languages[friendships[i][1]-1].size()); ++j) {
                lmemo2[languages[friendships[i][1]-1][j]-1] = true;
            }
            bool ok = false;
            for (int j=0; j<n; ++j) if (lmemo1[j] && lmemo2[j]) ok = true;
            if (!ok) ++cnt;
        }
        return cnt;
    }
};

int main(){
    return 0;
}
