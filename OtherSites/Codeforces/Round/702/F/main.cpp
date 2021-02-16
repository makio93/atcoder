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
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n);
        rep(i, n) cin >> a[i];
        map<int, int> cnt, cnt2;
        rep(i, n) cnt[a[i]]++;
        repi(itr, cnt) cnt2[itr->second]++;
        v(p(int)) b;
        repi(itr, cnt2) b.eb(itr->first, itr->second);
        int m = sz(b);
        if (m == 1) {
            cout << 0 << endl;
            continue;
        }
        v(p2(ll,int)) sum(m+1);
        v(ll) sum2(m+1);
        rep(i, m) {
            sum[i+1].first = sum[i].first + b[i].second;
            sum[i+1].second = b[i].first;
        }
        rep(i, m) {
            sum2[i+1] = sum2[i] + (ll)b[i].second * b[i].first;
        }
        ll ans = (ll)(1e15);
        rep(i, m) {
            ll sub = sum2[i] + (sum2[m]-sum2[i]) - (sum[m].first-sum[i].first) * b[i].first;
            ans = min(ans, sub);
        }
        cout << ans << endl;
    }
    return 0;
}
