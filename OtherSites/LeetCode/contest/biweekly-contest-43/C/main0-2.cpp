#include <bits/stdc++.h>
using namespace std;

// 本番終了後、自力研究、自力AC

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), cnt1 = 0, cnt2 = 0;
        list<char> ls, ls1, ls2;
        for (int i=0; i<n; ++i) ls.push_back(s[i]);
        ls1 = ls2 = ls;
        auto itr = ls1.begin();
        while (itr!=ls1.end()) {
            auto nitr = itr;
            ++nitr;
            if (nitr==ls1.end()) break;
            string now = { *itr, *nitr };
            while (now == "ab") {
                itr = ls1.erase(itr);
                itr = ls1.erase(itr);
                cnt1 += x;
                if (itr != ls1.begin()) --itr;
                nitr = itr;
                ++nitr;
                if (nitr==ls1.end()) break;
                now = { *itr, *nitr };
            }
            ++itr;
        }
        itr = ls1.begin();
        while (itr!=ls1.end()) {
            auto nitr = itr;
            ++nitr;
            if (nitr==ls1.end()) break;
            string now = { *itr, *nitr };
            while (now == "ba") {
                itr = ls1.erase(itr);
                itr = ls1.erase(itr);
                cnt1 += y;
                if (itr != ls1.begin()) --itr;
                nitr = itr;
                ++nitr;
                if (nitr==ls1.end()) break;
                now = { *itr, *nitr };
            }
            ++itr;
        }
        itr = ls2.begin();
        while (itr!=ls2.end()) {
            auto nitr = itr;
            ++nitr;
            if (nitr==ls2.end()) break;
            string now = { *itr, *nitr };
            while (now == "ba") {
                itr = ls2.erase(itr);
                itr = ls2.erase(itr);
                cnt2 += y;
                if (itr != ls2.begin()) --itr;
                nitr = itr;
                ++nitr;
                if (nitr==ls2.end()) break;
                now = { *itr, *nitr };
            }
            ++itr;
        }
        itr = ls2.begin();
        while (itr!=ls2.end()) {
            auto nitr = itr;
            ++nitr;
            if (nitr==ls2.end()) break;
            string now = { *itr, *nitr };
            while (now == "ab") {
                itr = ls2.erase(itr);
                itr = ls2.erase(itr);
                cnt2 += x;
                if (itr != ls2.begin()) --itr;
                nitr = itr;
                ++nitr;
                if (nitr==ls2.end()) break;
                now = { *itr, *nitr };
            }
            ++itr;
        }
        return max(cnt1, cnt2);
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int res = cl.maximumGain(s, x, y);
    cout << res << endl;
    return 0;
}
