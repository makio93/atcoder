#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.length();
        stack<int> st;
        for (int i=0; i<n; ++i) {
            if (S[i] == '(') st.push(-1);
            else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else {
                    int tval = 0;
                    while (st.top() != -1) {
                        tval += st.top() * 2;
                        st.pop();
                    }
                    st.pop();
                    st.push(tval);
                }
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main(){
    Solution cl;
    string s;
    cin >> s;
    cout << cl.scoreOfParentheses(s) << endl;
    return 0;
}
