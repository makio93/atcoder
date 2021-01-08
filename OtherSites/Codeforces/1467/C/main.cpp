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
    v(v(ll)) a(3);
    v(p2(ll,int)) b;
    ll sum = 0, sub = 0;
    rep(i, 3) {
        rep(j, n[i]) {
            ll ai;
            cin >> ai;
            a[i].pb(ai);
            b.eb(ai,i);
            sum += ai;
        }
    }
    VSORT(b);
    int g2 = b[0].second;
    bool ok = false;
    rep(i, 3) {
        if (i == g2) continue;
        if (sz(a[i]) > 1) ok = true; 
    }
    if (b[0].second!=b[1].second || !(b[0].second==b[1].second && !ok)) {
        sub = b[0].first + b[1].first;
        cout << (sum-sub*2) << endl;
    }
    else {
        rep(i, 3) { VSORT(a[i]) };
        v(ll) b2;
        rep(i, 3) {
            if (i == g2) continue;
            b2.pb(a[i][0]);
        }
        sub = b[0].first + min(b2[0], b2[1]);
        cout << (sum-sub*2) << endl;
    }
    return 0;
}
