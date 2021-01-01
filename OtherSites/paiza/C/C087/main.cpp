#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string nstr = to_string(n), rstr = nstr;
    reverse(rstr.begin(), rstr.end());
    while (nstr != rstr) {
        int val = stoi(nstr) + stoi(rstr);
        nstr = to_string(val);
        rstr = nstr;
        reverse(rstr.begin(), rstr.end());
    }
    cout << stoi(nstr) << endl;
    return 0;
}
