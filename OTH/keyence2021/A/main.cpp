#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
    v(ll) a(n), b(n), c;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll nval = 0;
    int ai = -1, bi = -1;
    priority_queue<p2(ll,int)> que;
    rep(i, n) {
        if (i==0) {
            ai = 0; bi = 0;
            nval = a[ai] * b[bi];
            que.emplace(a[0], ai);
        }
        else {
            que.emplace(a[i], -i);
            auto p = que.top();
            ll tval = p.first * b[i];
            if (tval > nval) {
                ai = p.second * -1;
                bi = i;
                nval = tval;
            }
        }
        c.pb(nval);
    }
    rep(i, n) cout << c[i] << endl;
    return 0;
}
