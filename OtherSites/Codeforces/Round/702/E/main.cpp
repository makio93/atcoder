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
        v(p2(ll,int)) a(n);
        rep(i, n) cin >> a[i].first;
        rep(i, n) a[i].second = i;
        VSORT(a);
        v(ll) sum(n+1);
        rep(i, n) sum[i+1] = sum[i] + a[i].first;
        int mid = 0;
        rep(i, n-1) {
            if (sum[i+1] < a[i+1].first) mid = max(mid, i+1);
        }
        v(int) ans;
        rep2(i, mid, n-1) ans.pb(a[i].second+1);
        VSORT(ans);
        cout << (n-mid) << endl;
        int m = sz(ans);
        rep(i, m) printf("%d%c", ans[i], (i<m-1?' ':'\n'));
    }
    return 0;
}
