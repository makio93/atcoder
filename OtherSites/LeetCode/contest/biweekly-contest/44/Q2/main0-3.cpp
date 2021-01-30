#include <bits/stdc++.h>
using namespace std;

// 本番後、自力研究、AC

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m2 = friendships.size();
        set<int> mcnt;
        for (int i=0; i<m2; ++i) {
            int ai = friendships[i][0]-1, bi = friendships[i][1]-1;
            bool ok = false;
            for (int j1=0; j1<(int)(languages[ai].size()); ++j1) {
                for (int j2=0; j2<(int)(languages[bi].size()); ++j2) {
                    if (languages[ai][j1] == languages[bi][j2]) ok = true;
                    if (ok) break;
                }
                if (ok) break;
            }
            if (!ok) {
                mcnt.insert(ai);
                mcnt.insert(bi);
            }
        }
        map<int, int> lcnt;
        for (auto itr=mcnt.begin(); itr!=mcnt.end(); ++itr) {
            for (int j=0; j<(int)(languages[*itr].size()); ++j) lcnt[languages[*itr][j]]++;
        }
        int msub = 0;
        for (auto p : lcnt) msub = max(msub, p.second);
        return (int)(mcnt.size()) - msub;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> languages(m);
    for (int i=0; i<m; ++i) {
        int mi;
        cin >> mi;
        for (int j=0; j<mi; ++j) {
            int li;
            cin >> li;
            languages[i].push_back(li);
        }
    }
    int fi;
    cin >> fi;
    vector<vector<int>> friendships(fi, vector<int>(2));
    for (int i=0; i<fi; ++i) cin >> friendships[i][0] >> friendships[i][1];
    cout << cl.minimumTeachings(n, languages, friendships) << endl;
    return 0;
}
