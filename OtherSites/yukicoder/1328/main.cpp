#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n;
    cin >> n;
    v(int) c(n), x(n), y(n);
    rep(i, n) {
        char ci, xi;
        cin >> ci >> xi >> y[i];
        c[i] = (ci=='R'?0:1);
        x[i] = (xi=='R'?0:1);
    }
    set<p(int)> y2;
    rep(i, n) y2.emplace(y[i], i);
    bool res = true;
    v(int) ans(n);
    while (!y2.empty()) {
        int now = 0;
        v(int) cnt(2);
        auto itr = y2.begin();
        bool moved = false;
        while (itr != y2.end()) {
            while (ans[now] != 0) {
                int tid = ans[now] - 1;
                cnt[x[tid]]++;
                ++now;
            }
            int yi = itr->first, id = itr->second;
            int xi = x[id], ci = c[id];
            if (yi != cnt[xi]) {
                if (yi < cnt[xi]) {
                    res = false;
                    break;
                }
                ++itr;
                moved = true;
                continue;
            }
            ans[now] = id + 1;
            ++now;
            cnt[ci]++;
            itr = y2.erase(itr);
            moved = true;
        }
        if (!moved) res = false;
        if (!res) break;
    }
    if (res) {
        cout << "Yes" << endl;
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    }
    else cout << "No" << endl;
    return 0;
}
