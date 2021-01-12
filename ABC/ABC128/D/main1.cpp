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

// 解説AC

int main(){
    int n, k;
    cin >> n >> k;
    v(int) d(n), rd;
    rep(i, n) cin >> d[i];
    rd = d;
    reverse(all(rd));
    ll ans = 0;
    int len = min(n, k);
    rep(a, len+1) for (int b=0; b<=len-a; ++b) {
        set<int> vmemo;
        ll sum = 0;
        rep(i, a) {
            sum += d[i];
            vmemo.insert(d[i]);
        }
        rep(i, b) {
            sum += rd[i];
            vmemo.insert(rd[i]);
        }
        ans = max(ans, sum);
        auto itr = vmemo.begin();
        rep(i, (k-(a+b))) {
            if (itr==vmemo.end()) break;
            if (*itr >= 0) break;
            sum -= *itr;
            ans = max(ans, sum);
            ++itr;
        }
    }
    cout << ans << endl;
    return 0;
}
