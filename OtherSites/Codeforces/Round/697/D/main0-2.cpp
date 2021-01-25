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
        int n, m;
        cin >> n >> m;
        v(int) a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        v(v(ll)) asort(2);
        rep(i, n) asort[b[i]-1].pb(a[i]);
        rep(i, 2) { VSORT(asort[i]); }
        int l1 = 0, l2 = 0;
        ll mcost = 0, ncost = 0;
        int ans = 0, nval = 0, mval = 0;
        rep(i, n) mcost += a[i];
        rep(i, n) mval += b[i];
        mcost -= m;
        if (mcost < 0) {
            cout << -1 << endl;
            continue;
        }
        while (l1<sz(asort[0]) && ncost+asort[0][l1]<=mcost) {
            ncost += asort[0][l1];
            ++nval;
            ++l1;
        }
        ans = max(ans, nval);
        while (l1>=0) {
            while (l2<sz(asort[1]) && ncost+asort[1][l2]<=mcost) {
                ncost += asort[1][l2];
                nval += 2;
                ++l2;
            }
            ans = max(ans, nval);
            if (l1-1>=0) {
                ncost -= asort[0][l1-1];
                --l1;
                --nval;
            }
            else break;
        }
        cout << (mval-ans) << endl;
    }
    return 0;
}
