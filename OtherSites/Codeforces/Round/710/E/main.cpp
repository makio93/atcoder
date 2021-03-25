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
        v(int) qi(n);
        rep(i, n) cin >> qi[i];
        v(v(int)) ans(2, v(int)(n));
        rep(i2, 2) {
            set<int> stock;
            rep(i, n) {
                if (i==0 || qi[i-1]!=qi[i]) {
                    int mval = (i==0) ? 0 : qi[i-1];
                    rep2(j, mval+1, qi[i]) stock.insert(j);
                    ans[i2][i] = qi[i];
                    stock.erase(qi[i]);
                }
                else {
                    if (i2 == 0) {
                        ans[i2][i] = *stock.begin();
                        stock.erase(stock.begin());
                    }
                    else {
                        ans[i2][i] = *stock.rbegin();
                        stock.erase(*stock.rbegin());
                    }
                }
            }
        }
        rep(i2, 2) {
            rep(i, n) printf("%d%c", ans[i2][i], (i<n-1?' ':'\n'));
        }
    }
    return 0;
}
