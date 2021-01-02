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

// 解説読んで提出したい（やりかけ）

int main(){
    int n;
    cin >> n;
    v(p(p(int))) xy(n);
    rep(i, n) {
        char ci, xi;
        cin >> ci >> xi >> xy[i].first.first;
        xy[i].first.second = ((ci==xi)?1:0);
        xy[i].second.first = ((xi=='R')?0:1);
        xy[i].second.second = i;
    }
    VSORT(xy);
    v(v(p2(p(int),int))) rb(2);
    rep(i, n) rb[xy[i].second.first].eb(xy[i].first, xy[i].second.second);
    v(int) cnt(2), id(2), ans(n);
    bool res = true;
    rep(i, n) {
        bool ok = false;
        rep(j, 2) {
            if (ok) break;
            if (id[j] >= sz(rb[j])) continue;
            if (cnt[j] == rb[j][id[j]].first.first) {
                ans[i] = rb[j][id[j]].second + 1;
                int ci = (rb[j][id[j]].first.second==1)?j:(1-j);
                cnt[ci]++;
                id[j]++;
                ok = true;
            }
        }
        if (!ok) {
            res = false;
            break;
        }
    }
    if (res) {
        cout << "Yes" << endl;
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    }
    else cout << "No" << endl;
    return 0;
}
