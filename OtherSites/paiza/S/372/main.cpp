#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define INF 1e9

struct SEG {
    int n;
    vector<int> dat;
    SEG(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<int>(2*n-1, (int)(INF));
    }
    void update(int k, int a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    int query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) r = n;
        if (r<=a || b<=l) return INF;
        if (a<=l && r<=b) return dat[k];
        else {
            int vl = query(a, b, k*2+1, l, (l+r)/2);
            int vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> x(n);
    for (int i=0; i<n; ++i) {
        cin >> x[i].first;
        x[i].second = i;
    }
    set<int> st;
    for (int i=0; i<n; ++i) st.insert(i);
    st.insert(n);
    SEG sg(n+1);
    for (int i=0; i<n; ++i) sg.update(i, x[i].first);
    sort(x.begin(), x.end());
    int cnt = n;
    for (int i=0; i<n; ++i) {
        auto itr = st.find(x[i].second);
        if (i==n-1) {
            if (x[i].first >= m) ++cnt;
        }
        else {
            auto litr = itr, ritr = itr;
            if (litr!=st.begin()) --litr;
            ++ritr;
            int mval = sg.query(*litr, (*ritr)+1);
            if (x[i].first-mval >= m) ++cnt;
        }
        st.erase(itr);
    }
    cout << cnt << endl;
    return 0;
}
