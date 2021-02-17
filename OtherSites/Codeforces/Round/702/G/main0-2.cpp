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

// 本番後自主研究分

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(ll) a(n), x(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> x[i];
        v(ll) asum(n+1);
        rep(i, n) asum[i+1] = asum[i] + a[i];
        ll add = max(0LL, asum[n]);
        if (asum[n] <= 0) {
            ll amax = (ll)(-LINF), xmax = 0;
            rep(i, n) amax = max(amax, asum[i]);
            rep(i, m) xmax = max(xmax, x[i]);
            if (xmax > amax) {
                rep(j, m) printf("-1%c", (j<m-1?' ':'\n'));
                continue;
            }
        }
        v(p2(ll,int)) x2(m);
        rep(i, m) {
            x2[i].first = x[i];
            x2[i].second = i;
        }
        v(ll) ans(m, (ll)(LINF)), bval(m);
        auto x3 = x2;
        if (add > 0) {
            rep(i, m) {
                bval[i] += x3[i].first / add * n;
                x3[i].first %= add;
            }
        }
        VSORT(x2);
        if (add > 0) VSORT(x3);
        rep(i, n) {
            if (asum[i+1] < 0) continue;
            auto itr = lower_bound(x2.begin(), x2.end(), p2(ll,int){asum[i+1]+1,-1});
            if (itr != x2.begin()) {
                itr = prev(itr);
                ll nval1 = (ll)i;
                if (add > 0) nval1 = max(0LL, nval1-(asum[i+1]-itr->first)/add);
                ans[itr->second] = min(ans[itr->second], nval1);
            }
            if (add <= 0) continue; 
            auto itr2 = lower_bound(x3.begin(), x3.end(), p2(ll,int){asum[i+1]+1,-1});
            if (itr2 != x3.begin()) continue;
            ll nval = bval[itr2->second] + i;
            if (add > 0) nval = max(0LL, nval-(asum[i+1]-itr2->first)/add);
            ans[itr2->second] = min(ans[itr2->second], nval);
        }
        if (add > 0) {
            repr(i, m-1) ans[x3[i].second] = min(ans[x3[i].second], ans[x3[i+1].second]);
        }
        repr(i, m-1) ans[x2[i].second] = min(ans[x2[i].second], ans[x2[i+1].second]);
        rep(i, m) printf("%lld%c", ans[i], (i<m-1?' ':'\n'));
    }
    return 0;
}
