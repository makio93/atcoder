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
    map<int, set<int>> prime;
    rep(i, n) {
        vp(int) plst;
        int tval = x[i];
        for (int j=2; j*j<=tval; ++j) {
            if (tval%j == 0) prime[j].insert(i);
            while (tval%j==0) tval /= j;
        }
        if (tval > 1) prime[tval].insert(i);
    }
    set<int> ids;
    rep(i, n) ids.insert(i);
    v(p2(int,int)) plst;
    repi(itr, prime) plst.eb(sz(itr->second),-(itr->first));
    RSORT(plst);
    rep(i, sz(plst)) plst[i].second *= -1;
    ll ans = 1;
    rep(i, sz(plst)) {
        bool ok = false;
        repi(itr, prime[plst[i].second]) if (ids.find(*itr) != ids.end()) ok = true;
        if (!ok) continue;
        ans *= plst[i].second;
        repi(itr, prime[plst[i].second]) ids.erase(*itr);
        if (ids.empty()) break;
    }
    cout << ans << endl;
    return 0;
}
