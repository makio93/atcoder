#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, n;
    cin >> a >> b >> c >> d >> e >> n;
    vector<int> f(n), t(n), s(n);
    for (int i=0; i<n; ++i) {
        string ti, si;
        cin >> f[i] >> ti >> si;
        t[i] = stoi(ti.substr(0, 2)) * 60 * 60 + stoi(ti.substr(3, 2)) * 60;
        s[i] = stoi(si.substr(0, 2)) * 60 * 60 + stoi(si.substr(3, 2)) * 60;
    }
    set<pair<int, int>> oc;
    for (int i=0; i<n; ++i) {
        pair<int, int> data = { 0, 0 };
        if (f[i] == 0) {
            data.second = t[i] - a;
            data.first = s[i] + b;
        }
        else {
            data.second = t[i] - c;
            data.first = t[i] + d;
        }
        oc.insert(data);
    }
    auto itr = oc.begin();
    while (itr != oc.end()) {
        auto pitr = itr;
        ++itr;
        if (itr == oc.end()) break;
        int l = pitr->first, r = itr->second;
        if (r <= l) {
            int nl = pitr->second, nr = itr->first;
            pair<int, int> ndata = { nr, nl };
            ++itr;
            itr = oc.erase(pitr, itr);
            itr = oc.insert(itr, ndata);
        }
    }
    itr = oc.begin();
    while (itr != oc.end()) {
        auto pitr = itr;
        ++itr;
        if (itr == oc.end()) break;
        int l = pitr->first + e, r = itr->second;
        if (r <= l) {
            int nl = pitr->second, nr = itr->first;
            pair<int, int> ndata = { nr, nl };
            ++itr;
            itr = oc.erase(pitr, itr);
            itr = oc.insert(itr, ndata);
        }
    }
    for (auto itr=oc.begin(); itr!=oc.end(); ++itr) {
        int cl = itr->second, op = itr->first;
        vector<int> cls(3), ops(3);
        for (int i=2; i>=0; --i) {
            if (i>0) {
                cls[i] = cl % 60;
                cl /= 60;
            }
            else cls[i] = cl;
        }
        for (int i=2; i>=0; --i) {
            if (i>0) {
                ops[i] = op % 60;
                op /= 60;
            }
            else ops[i] = op;
        }
        for (int i=0; i<3; ++i) {
            printf("%02d", cls[i]);
            if (i<2) cout << ':';
        }
        cout << " - ";
        for (int i=0; i<3; ++i) {
            printf("%02d", ops[i]);
            if (i<2) cout << ':';
        }
        cout << endl;
    }
    return 0;
}
