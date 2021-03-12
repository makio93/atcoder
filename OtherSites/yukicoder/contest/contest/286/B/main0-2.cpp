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
    int t;
    cin >> t;
    rep(i1, t) {
        v(p2(ll,int)) r(3);
        rep(i, 3) {
            cin >> r[i].first;
            r[i].second = i;
        }
        VSORT(r);
        v(ll) ans(3);
        ans[r[2].second] = 1;
        ans[r[0].second] = r[2].first / r[0].first, ans[r[1].second] = r[2].first / r[1].first;
        while ((ans[r[0].second]+1)*r[0].first <= r[2].first) ++ans[0];
        while ((ans[r[1].second]+1)*r[1].first <= r[2].first) ++ans[1];
        rep(i, 3) ans[r[i].second] *= r[i].first;
        rep(i, 3) printf("%lld%c", ans[i], (i<2?' ':'\n'));
    }
    return 0;
}
