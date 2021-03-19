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
    string s;
    cin >> s;
    v(int) a(n);
    rep(i, n) cin >> a[i];
    v(ll) sum(n+1);
    rep(i, n) sum[i+1] = sum[i] + (s[i]=='R'?a[i]:-a[i]);
    v(v(ll)) l(2, v(ll)(n+1)), r(2, v(ll)(n+2));
    r[0].back() = (ll)(LINF); r[1].back() = (ll)(-LINF);
    rep(i, n) {
        l[0][i+1] = min(l[0][i], sum[i+1]);
        l[1][i+1] = max(l[1][i], sum[i+1]);
    }
    rep2r(i, 1, n) {
        r[0][i] = min(r[0][i+1], sum[i]);
        r[1][i] = max(r[1][i+1], sum[i]);
    }
    ll ans = (ll)(-LINF);
    rep2(i, 1, n) {
        ans = max(ans, llabs(r[1][i]-l[0][i-1]));
        ans = max(ans, llabs(l[1][i-1]-r[0][i]));
    }
    cout << ans << endl;
    return 0;
}
