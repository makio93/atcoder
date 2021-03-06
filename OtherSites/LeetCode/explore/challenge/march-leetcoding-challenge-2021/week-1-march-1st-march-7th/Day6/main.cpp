#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        vector<pair<int, string>> slst;
        for (int i=0; i<n; ++i) {
            string rstr = words[i];
            reverse(rstr.begin(), rstr.end());
            slst.emplace_back((int)(rstr.size()), rstr);
        }
        sort(slst.rbegin(), slst.rend());
        int res = 0;
        vector<set<string>> dic(8);
        for (int i=0; i<n; ++i) {
            if (dic[slst[i].first].find(slst[i].second) == dic[slst[i].first].end()) {
                res += slst[i].first + 1;
                for (int j=1; j<=slst[i].first; ++j) dic[j].insert(slst[i].second.substr(0, j));
            }
        }
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i=0; i<n; ++i) cin >> words[i];
    cout << cl.minimumLengthEncoding(words) << endl;
    return 0;
}
