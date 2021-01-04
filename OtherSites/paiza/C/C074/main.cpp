#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, x;
    cin >> h >> w >> x;
    string s;
    for (int i=0; i<h; ++i) {
        string si;
        cin >> si;
        s += si;
    }
    vector<string> a;
    for (int p=0; p<h*w; p+=x) a.push_back(s.substr(p, x));
    for (int i=0; i<(int)(a.size()); ++i) cout << a[i] << endl;
    return 0;
}
