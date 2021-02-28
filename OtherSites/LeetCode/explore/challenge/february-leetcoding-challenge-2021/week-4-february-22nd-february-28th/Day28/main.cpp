#include <bits/stdc++.h>
using namespace std;

class FreqStack {
    map<int, int> cnt;
    map<int, stack<int>> st;
public:
    FreqStack() {}
    void push(int x) {
        int xcnt = 0;
        if (cnt.find(x) != cnt.end()) xcnt = cnt[x];
        st[xcnt+1].push(x);
        cnt[x]++;
    }
    int pop() {
        int xpop = st.rbegin()->second.top();
        st.rbegin()->second.pop();
        if (st.rbegin()->second.empty()) st.erase(prev(st.end()));
        cnt[xpop]--;
        if (cnt[xpop] == 0) cnt.erase(xpop);
        return xpop;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

int main(){
    return 0;
}
