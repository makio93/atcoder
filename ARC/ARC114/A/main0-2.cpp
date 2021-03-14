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

int main(){
    int n;
    cin >> n;
    v(int) x(n);
    rep(i, n) cin >> x[i];
    set<int> prime, nprime;
    v(int) pval = { 2, 3, 5, 7 };
    rep(i, n) {
        bool pr = true;
        rep(j, sz(pval)) if (x[i]%pval[j] == 0) pr = false;
        if (pr) prime.insert(x[i]);
        else nprime.insert(x[i]);
    }
    ll mul = 1;
    if (!nprime.empty()) {
        mul = (int)(INF);
        rep(i, 1<<4) {
            if (i == 0) continue;
            bool ok = true;
            repi(itr, nprime) {
                bool ok2 = false;
                rep(j, 4) if ((i>>j)&1) {
                    if ((*itr)%pval[j] == 0) ok2 = true;
                }
                if (!ok2) ok = false;
            }
            if (ok) {
                ll tmul = 1;
                rep(j, 4) if ((i>>j)&1) tmul *= pval[j];
                mul = min(mul, tmul);
            }
        }
    }
    ll ans = mul;
    repi(itr, prime) ans *= (*itr);
    cout << ans << endl;
    return 0;
}
