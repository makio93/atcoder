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

// 本番中の作成分

using mint = modint;

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        ll x, y, p, q;
        cin >> x >> y >> p >> q;

        mint::set_mod(p+q);
        ll add = 2 * (x + y);
        p(int) mval = { (int)(INF), (int)(INF) };
        for (ll xi=x; xi<x+y; ++xi) {
            set<ll> finished;
            mint txi = xi;
            while (finished.find(txi.val()) == finished.end()) {
                if (txi.val()>=p && txi.val()<p+q) {
                    mval = min(mval, {sz(finished), xi});
                    break;
                }
                finished.insert(txi.val());
                txi += add;
            }
        }
        if (mval == (p(int)){(int)(INF),(int)(INF)}) cout << "infinity" << endl;
        else {
            ll ans = (ll)mval.second + add * mval.first;
            cout << ans << endl;
        }
    }
    return 0;
}
