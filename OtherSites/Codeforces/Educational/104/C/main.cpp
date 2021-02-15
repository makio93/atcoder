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
        int m = n * (n-1) / 2;
        vector<int> sum = { m/n, m/n+m%n*2/n }, ans;
        rep(i, n) {
            int cnt = 0;
            for (int j=i+1; j<n; ++j) {
                ++cnt;
                const vector<int> vals = { 1, 0, -1 };
                int nval = 0;
                rep(i2, 3) {
                    if (i2 == 2) nval = vals[i2];
                    else if (cnt <= sum[i2]) {
                        nval = vals[i2];
                        break;
                    }
                }
                ans.pb(nval);
            }
        }
        rep(i, sz(ans)) printf("%d%c", ans[i], (i<sz(ans)-1?' ':'\n'));
    }
    return 0;
}
