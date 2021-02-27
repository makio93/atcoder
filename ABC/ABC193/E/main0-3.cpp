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

unsigned long long gcd(unsigned long long a, unsigned long long b) { return b ? gcd(b, a % b) : a; }
unsigned long long lcm(unsigned long long a, unsigned long long b) { return a / gcd(a, b) * b; }

// 本番終了後、自力研究、WA

using mint = modint;

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;
        ll ans = (ll)(1.5e18);
        for (ll xi=x; xi<x+y; ++xi) {
            for (ll yi=p-xi; yi<p+q-xi; ++yi) {
                ll nyi = (yi>=0?yi:(p+q)-(yi%(p+q)+(p+q)));
                ll qval = 2 * (x + y), rval = p + q;
                ll gval = gcd(qval,rval);
                qval /= gval; rval /= gval;
                if (rval == 1LL) {
                    if (nyi == 0) ans = min(ans, xi);
                    continue;
                }
                mint::set_mod(rval);
                mint nval = nyi;
                nval /= qval;
                if (nval.val()*2LL>=(ll)(1.5e18)/(x+y)) continue;
                ans = min(ans, min((ll)(1.5e18), xi+nval.val()*2LL*(x+y)));
            }
        }
        if (ans == (ll)(1.5e18)) cout << "infinity" << endl;
        else cout << ans << endl;
    }
    return 0;
}
