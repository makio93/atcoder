#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size(), m = pieces.size();
        vector<int> place(n);
        for (int i=0; i<m; ++i) {
            bool ok = false;
            int mlen = pieces[i].size();
            for (int j=0; j+mlen-1<n; ++j) {
                bool ok2 = true;
                for (int k=0; k<mlen; ++k) if (arr[j+k] != pieces[i][k]) ok2 = false;
                if (ok2) {
                    for (int k=0; k<mlen; ++k) place[j+k]++;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
        bool ans = true;
        for (int i=0; i<n; ++i) if (place[i] != 1) ans = false;
        return ans;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; ++i) cin >> arr[i];
    cin >> m;
    vector<vector<int>> pieces(m);
    for (int i=0; i<m; ++i) {
        int mlen;
        cin >> mlen;
        for (int j=0; j<mlen; ++j) {
            int mi;
            cin >> mi;
            pieces[i].push_back(mi);
        }
    }
    bool res = cl.canFormArray(arr, pieces);
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
