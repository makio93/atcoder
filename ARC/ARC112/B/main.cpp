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
    ll b, c;
    cin >> b >> c;
    if (c == 1) {
        if (b == 0) cout << 1 << endl;
        else cout << 2 << endl;
        return 0;
    }
    ll ans = 0;
    if (b < 0) {
        ans = 1 + c / 2 + (c-1) / 2 + 1 + min((c-1)/2, llabs(b)) + min((c-2)/2, llabs(b)-1);
    }
    else if (b > 0) {
        ans = 1 + (c-1) / 2 + 1 + (c-2) / 2 + min(c/2, llabs(b)) + min((c-1)/2, llabs(b)-1);
    }
    else {
        ans = c / 2 + (c-1) / 2 + 1;
    }
    cout << ans << endl;
    return 0;
}
