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

// 解説を見て実装

int calc(v(int)& a, v(int)& b) {
    int n = a.size(), m = b.size();
    if (n==0 || m==0) return 0;
    vp(int) s(n+1);
    int j = m-1;
    s[n] = { 0, m };
    repr(i, n) {
        while (b[j] > a[i]) --j;
        if (a[i] == b[j]) {
            s[i].first = s[i+1].first + 1;
            s[i].second = j;
        }
        else s[i] = s[i+1];
    }
    int res = 0, j1 = 0, j2 = 0;
    rep(i, m) {
        while (j1<n && a[j1]<=b[i]+j1) ++j1;
        while (j2<m && b[j2]<=b[i]+j1-1) ++j2;
        res = max(res, (j2-i)+s[j1].first);
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(int) a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        v(int) ap, bp, an, bn;
        rep(i, n) {
            if (a[i] >= 0) ap.pb(a[i]);
            else an.pb(-a[i]);
        }
        rep(i, m) {
            if (b[i] >= 0) bp.pb(b[i]);
            else bn.pb(-b[i]);
        }
        reverse(all(an)); reverse(all(bn));
        cout << (calc(ap,bp)+calc(an,bn)) << endl;
    }
    return 0;
}
