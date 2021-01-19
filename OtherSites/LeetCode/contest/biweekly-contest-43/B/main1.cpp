#include <bits/stdc++.h>
using namespace std;

// hintの内容を見てあらためて提出し、AC

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        vector<pair<string, int>> score = { { "ab", x }, { "ba", y } };
        if (y > x) swap(score[0], score[1]);
        stack<char> st, st2;
        int res = 0;
        for (int i=0; i<n; ++i) {
            st.push(s[i]);
            if (st.size() < 2) continue;
            if (st.top() != score[0].first[1]) continue;
            string tar;
            tar.push_back(st.top()); st.pop();
            tar.push_back(st.top());
            reverse(tar.begin(), tar.end());
            if (tar == score[0].first) {
                res += score[0].second;
                st.pop();
            }
            else st.push(score[0].first[1]);
        }
        while (!st.empty()) {
            string tar;
            st2.push(st.top()); st.pop();
            if (st.empty()) break;
            tar.push_back(st.top());
            tar.push_back(st2.top());
            while (tar==score[1].first) {
                res += score[1].second;
                st.pop(); st2.pop();
                if (st.empty() || st2.empty()) break;
                tar = "";
                tar.push_back(st.top());
                tar.push_back(st2.top());
            }
        }
        return res;
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
