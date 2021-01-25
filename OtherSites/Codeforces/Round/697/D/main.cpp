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
        v(p2(ll,int)) asort(n);
        rep(i, n) {
            asort[i] = { (ll)(a[i]), i };
            if (b[i] == 1) asort[i].first *= 2;
        }
        VSORT(asort);
        ll mcost = 0, ncost = 0;
        rep(i, n) mcost += a[i];
        mcost -= m;
        if (mcost < 0) {
            cout << -1 << endl;
            continue;
        }
        int sval = 0, nval = 0;
        rep(i, n) sval += b[i];
        rep(i, n) {
            if (ncost+a[asort[i].second] <= mcost) {
                ncost += a[asort[i].second];
                nval += b[asort[i].second];
            }
        }
        cout << (sval-nval) << endl;
    }
    return 0;
}
