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
    ll x, y;
    cin >> n >> x >> y;
    v(ll) a(n);
    rep(i, n) cin >> a[i];
    v(ll) lsum(n+1), rsum(n+1);
    rep(i, n) lsum[i+1] = lsum[i] + a[i];
    repr(i, n) rsum[i] = rsum[i+1] + a[i];
    v(v(ll)) dpx(n+1, v(ll)(2, 0)), dpy(n+1, v(ll)(2, 0));
    rep(i, n) {
        dpx[i+1][1] = max(dpx[i+1][1], dpx[i][1]+x);
        dpx[i+1][1] = max(dpx[i+1][1], lsum[i]+x);
        dpx[i+1][0] = max(dpx[i+1][0], dpx[i][1]+a[i]);
        dpx[i+1][0] = max(dpx[i+1][0], dpx[i][0]+a[i]);
        if (i==0) {
            dpx[1][0] = dpx[1][1];
        }
    }
    rep2r(i, 1, n) {
        dpy[i-1][1] = max(dpy[i-1][1], dpy[i][1]+y);
        dpy[i-1][1] = max(dpy[i-1][1], rsum[i]+y);
        dpy[i-1][0] = max(dpy[i-1][0], dpy[i][1]+a[i-1]);
        dpy[i-1][0] = max(dpy[i-1][0], dpy[i][0]+a[i-1]);
        if (i==n) {
            dpy[n-1][0] = dpy[n-1][1];
        }
    }
    rep2(i, 2, n-1) {
        cout << (max(dpx[i-1][0],dpx[i-1][1])+max(dpy[i][0],dpy[i][1])+a[i-1]) << endl;
    }
    return 0;
}
