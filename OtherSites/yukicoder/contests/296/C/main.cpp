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
    v(int) a(n);
    rep(i, n) cin >> a[i];
    v(v(int)) b(n, v(int)(n));
    rep(i, n) rep(j, n) cin >> b[i][j];
    p2(ll,int) mval = { (ll)(-LINF), 0 };
    rep(i, (1<<n)) {
        if (i==0) continue;
        ll sum = 0;
        rep(j, n) {
            if ((i>>j)&1) {
                sum += a[j];
                rep2(j2, j, n-1) if ((i>>j2)&1) sum += b[j][j2];
            }
        }
        mval = max(mval, { sum, i });
    }
    cout << mval.first << endl;
    v(int) ans;
    rep(i, n) if ((mval.second>>i)&1) ans.pb(i+1);
    rep(i, sz(ans)) printf("%d%c", ans[i], (i<sz(ans)-1?' ':'\n'));
    return 0;
}
