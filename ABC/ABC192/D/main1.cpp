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

// 解説AC

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if (sz(x) == 1) {
        if ((ll)(x[0]-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int mval = 0;
    rep(i, sz(x)) mval = max(mval, (int)(x[i]-'0'));
    if ((ll)(mval+1) > m) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 1, r = m+1;
    while (r-l > 1) {
        ll c = (l+r) / 2, tval = 0;
        rep(i, sz(x)) {
            if (tval>m/c) {
                tval = m + 1;
                break;
            }
            tval *= c;
            tval += (ll)(x[i]-'0');
            if (tval > m) break;
        }
        if (tval <= m) l = c;
        else r = c;
    }
    cout << max(0LL, l-(ll)mval) << endl;
    return 0;
}
