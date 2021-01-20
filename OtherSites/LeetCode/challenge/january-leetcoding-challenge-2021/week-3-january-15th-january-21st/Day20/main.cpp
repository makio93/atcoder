#include <bits/stdc++.h>
using namespace std;

class Solution {
    const string pars = "()[]{}";
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        bool ok = true;
        for (int i=0; i<n; ++i) {
            if (!ok) break;
            for (int j=0; j<6; ++j) if (s[i] == pars[j]) {
                if (j%2==0) st.push(s[i]);
                else {
                    if (!st.empty() && pars[j-1]==st.top()) st.pop();
                    else ok = false;
                }
            }
        }
        if (ok && !st.empty()) ok = false;
        return ok;
    }
};

int main(){
    return 0;
}
