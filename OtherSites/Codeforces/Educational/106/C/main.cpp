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
        v(int) c(n);
        rep(i, n) cin >> c[i];
        v(v(ll)) mval(2);
        rep(i2, 2) {
            int cmin = (int)(INF);
            ll csum = 0;
            rep2(i, 0, (n+1)/2) {
                if (i2+i*2 >= n) continue;
                csum += c[i2+i*2];
                cmin = min(cmin, c[i2+i*2]);
                mval[i2].pb((csum-cmin)+(ll)(cmin)*(n-i));
            }
        }
        ll ans = (ll)(LINF);
        rep(i, sz(mval[0])) {
            rep2(j, -1, 0) if (i+(i+j)>=0 && i+(i+j)<=n-1 && (i+j)<sz(mval[1])) {
                ans = min(ans, mval[0][i]+mval[1][i+j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
