#include <bits/stdc++.h>
using namespace std;

class SyllableCountEstimator {
    const vector<char> vow = { 'a', 'e', 'i', 'o', 'u' };
    const vector<string> sub = { "au", "oa", "oo", "iou" };
public:
    int estimate(string W) {
        int n = W.size(), cnt = 0;
        for (int i=0; i<n; ++i) {
            bool ok = false;
            for (int j=0; j<(int)(vow.size()); ++j) if (W[i] == vow[j]) ok = true;
            if (ok) ++cnt;
        }
        for (int i=0; i<n; ++i) {
            bool ok = false;
            for (int j=0; j<(int)(sub.size()); ++j) {
                if (n>=(int)(sub[j].size()) && W.substr(i,(int)(sub[j].size())) == sub[j]) ok = true;
            }
            if (ok) --cnt;
        }
        if (W.back() == 'e') --cnt;
        if (n>=2 && W.substr(n-2,2)=="le" && n>2) {
            bool ok = false;
            for (int i=0; i<(int)(vow.size()); ++i) if (W[n-3] == vow[i]) ok = true;
            if (!ok) ++cnt;
        }
        if (cnt == 0) cnt = 1;
        return cnt;
    }
};

int main(){
    return 0;
}
