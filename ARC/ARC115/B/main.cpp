#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

const string YES = "Yes";
const string NO = "No";

int main(){
    int n;
    cin >> n;
    v(v(ll)) c(n, v(ll)(n));
    rep(i, n) rep(j, n) cin >> c[i][j];
    v(ll) a(n), b(n);
    rep(i, n) a[i] = c[i][0];
    bool ans = true;
    rep2(i, 1, n-1) {
        b[i] = c[0][i] - c[0][0];
        rep2(j, 1, n-1) {
            if (c[j][i]-c[j][0] != b[i]) {
                ans = false;
                break;
            }
        }
        if (!ans) break;
    }
    if (ans) {
        ll mvala = (ll)(LINF), mvalb = (ll)(LINF);
        rep(i, n) mvala = min(mvala, a[i]);
        rep(i, n) mvalb = min(mvalb, b[i]);
        if (mvalb < 0) {
            mvala = -mvalb;
            rep(i, n) a[i] -= mvala;
            rep(i, n) b[i] -= mvalb;
        }
        cout << "Yes" << endl;
        rep(i, n) printf("%lld%c", a[i], (i<n-1?' ':'\n'));
        rep(i, n) printf("%lld%c", b[i], (i<n-1?' ':'\n'));
    }
    else cout << "No" << endl;
    return 0;
}
