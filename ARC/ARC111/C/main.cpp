#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
//#define p(t) pair<t, t>
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
    v(int) a(n), b(n), p(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) if (p[i] == i) p[i] = -1;
    bool ok = true;
    rep(i, n) {
        if (p[i] == -1) continue;
        if (a[i] <= b[p[i]]) ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    v(p2(int,int)) ans;
    rep(i, n) {
        if (p[i] == -1) continue;
        if (i == p[p[i]]) {
            ans.eb(i+1, p[i]+1);
            p[p[i]] = -1; p[i] = -1;
        }
    }
    v(p2(int,int)) wlst;
    v(int) revp(n, -1);
    rep(i, n) {
        if (p[i] == -1) continue;
        wlst.eb(b[p[i]], p[i]);
        revp[p[i]] = i;
    }
    RSORT(wlst);
    rep(i, sz(wlst)) {
        int i2 = revp[wlst[i].second], j2 = wlst[i].second;
        if (i2 == -1) continue;
        if (p[i2]==-1 || p[j2]==-1) continue;
        if (i2 == j2) {
            revp[p[i2]] = -1;
            p[i2] = -1;
            continue;
        }
        ans.eb(i2+1, j2+1);
        p[i2] = p[j2];
        revp[p[i2]] = i2;
        p[j2] = -1;
        revp[j2] = -1;
    }
    cout << sz(ans) << endl;
    rep(i, sz(ans)) cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
