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
        int n;
        cin >> n;
        v(p2(p(int),int)) hw(n);
        rep(i, n) {
            int hi, wi;
            cin >> hi >> wi;
            if (hi > wi) swap(hi, wi);
            hw[i] = { { hi, -wi }, i+1 };
        }
        RSORT(hw);
        rep(i, n) hw[i].first.second *= -1;
        vp(int) mval(n+1, {(int)(INF+5), n+1});
        repr(i, n) mval[i] = min(mval[i+1], { hw[i].first.second, hw[i].second });
        v(int) ans(n);
        rep(i, n) {
            int id = hw[i].second - 1;
            if (mval[i+1].first < hw[i].first.second) ans[id] = mval[i+1].second;
            else ans[id] = -1;
        }
        rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    }
    return 0;
}
