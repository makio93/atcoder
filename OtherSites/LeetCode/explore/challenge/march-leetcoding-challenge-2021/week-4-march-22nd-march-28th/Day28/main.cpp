#include <bits/stdc++.h>
using namespace std;

class Solution {
    const vector<string> nstr = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const vector<int> iord = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
public:
    string originalDigits(string s) {
        int n = s.length();
        vector<int> ccnt(26);
        for (int i=0; i<n; ++i) ccnt[s[i]-'a']++;
        vector<int> dcnt(10, (int)(1e9));
        string ans;
        for (int i1=0; i1<10; ++i1) {
            string nstri = nstr[iord[i1]];
            sort(nstri.begin(), nstri.end());
            vector<pair<int, int>> ccnti;
            for (int i=0; i<(nstri.length()); ++i) {
                if (i-1<0 || nstri[i]!=nstri[i-1]) ccnti.emplace_back((int)(nstri[i]-'a'), 1);
                else ccnti.back().second++;
            }
            for (int i=0; i<(int)(ccnti.size()); ++i) dcnt[iord[i1]] = min(dcnt[iord[i1]], ccnt[ccnti[i].first]/ccnti[i].second);
            for (int i=0; i<(int)(ccnti.size()); ++i) ccnt[ccnti[i].first] -= dcnt[iord[i1]] * ccnti[i].second;
        }
        for (int i=0; i<10; ++i) if (dcnt[i] > 0) ans += string(dcnt[i], (char)('0'+i));
        return ans;
    }
};

int main(){
    return 0;
}
