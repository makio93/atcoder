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
    map<int, int> oc;
    for (int i=0; i<n; ++i) {
        int ti, si;
        if (f[i] == 0) {
            ti = t[i] - a;
            si = s[i] + b + e;
        }
        else {
            ti = t[i] - c;
            si = t[i] + d + e;
        }
        oc[ti]++;
        oc[si]--;
    }
    map<int, int> oc2;
    int tti = -1, nval = 0;
    for (auto p : oc) {
        bool zero = (nval==0);
        nval += p.second;
        if (zero && nval>0) {
            tti = p.first;
        }
        if (!zero && nval==0) {
            oc2[tti] = 1;
            oc2[p.first-e] = -1;
            tti = -1;
        }
    }
    vector<pair<int, int>> ans;
    tti = -1, nval = 0;
    for (auto p : oc2) {
        bool zero = (nval==0);
        nval += p.second;
        if (zero && nval>0) {
            tti = p.first;
        }
        if (!zero && nval==0) {
            ans.emplace_back(tti, p.first);
            tti = -1;
        }
    }
    for (int i=0; i<(int)(ans.size()); ++i) {
        vector<int> cls(3), ops(3);
        int cli = ans[i].first, opi = ans[i].second;
        for (int i=2; i>=0; --i) {
            if (i>0) {
                cls[i] = cli % 60;
                cli /= 60;
            }
            else cls[i] = cli;
        }
        for (int i=2; i>=0; --i) {
            if (i>0) {
                ops[i] = opi % 60;
                opi /= 60;
            }
            else ops[i] = opi;
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
