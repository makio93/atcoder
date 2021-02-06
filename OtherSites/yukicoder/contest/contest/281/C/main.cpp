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
    v(ll) c(n), c2;
    rep(i, n) cin >> c[i];
    c2 = c;
    RSORT(c);
    VSORT(c2);
    v(ll) sum(4);
    ll aval = 0, bval = 0;
    rep(i, n) {
        if (i%2==0) aval += c[i];
        else bval += c[i];
    }
    sum[0] = llabs(aval) - llabs(bval);
    aval = 0; bval = 0;
    rep(i, (n+1)/2) aval += c[i];
    rep(i, n/2) bval += c2[i];
    sum[1] = llabs(aval) - llabs(bval);
    swap(c, c2);
    aval = 0; bval = 0;
    rep(i, n) {
        if (i%2==0) aval += c[i];
        else bval += c[i];
    }
    sum[2] = llabs(aval) - llabs(bval);
    aval = 0; bval = 0;
    rep(i, (n+1)/2) aval += c[i];
    rep(i, n/2) bval += c2[i];
    sum[3] = llabs(aval) - llabs(bval);
    cout << max(min(sum[0],sum[1]),min(sum[2],sum[3])) << endl;
    return 0;
}
