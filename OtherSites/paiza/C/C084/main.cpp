#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    cout << string(n+2, '+') << endl;
    cout << '+' << s << '+' << endl;
    cout << string(n+2, '+') << endl;
    return 0;
}
