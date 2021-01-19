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
    v(int) n(3);
    rep(i, 3) cin >> n[i];
    v(v(int)) a(3);
    rep(i, 3) {
        rep(j, n[i]) {
            int aj;
            cin >> aj;
            a[i].pb(aj);
        }
    }
    v(ll) sum(3);
    rep(i, 3) rep(j, n[i]) sum[i] += a[i][j];
    VSORT(sum);
    rep(i, 3) VSORT(a[i]);
    v(int) mval(3);
    rep(i, 3) mval[i] = a[i].front();
    VSORT(mval);
    ll sub1 = sum.front(), sub2 = mval[0] + mval[1];
    ll asub = 0;
    rep(i, 3) asub += sum[i];
    cout << (asub-min(sub1,sub2)*2) << endl;
    return 0;
}
