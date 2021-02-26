#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), id1 = 0, id2 = 0;
        stack<int> st;
        while (id1<n) {
            if (id1 < n) {
                st.push(pushed[id1]);
                ++id1;
            }
            while (!st.empty() && id2<n && st.top()==popped[id2]) {
                st.pop();
                ++id2;
            }
        }
        return (st.empty());
    }
};

int main() {
    Solution cl;
    int n;
    cin >> n;
    vector<int> pushed(n), popped(n);
    for (int i=0; i<n; ++i) cin >> pushed[i];
    for (int i=0; i<n; ++i) cin >> popped[i];
    if (cl.validateStackSequences(pushed, popped)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
