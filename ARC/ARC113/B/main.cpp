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

using mint = modint;
const v(int) sval = { 0, 0, 4, 4, 2, 0, 0, 4, 4, 2 };

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    int one = (int)(a % 10);
    if (sval[one] == 0) {
        cout << one << endl;
    }
    else {
        mint::set_mod((ll)(sval[one]));
        mint ex = b;
        ex = ex.pow(c);
        ll lex = ex.val();
        if (lex == 0) lex = (ll)(sval[one]);
        mint::set_mod(10);
        mint ans = (ll)(one);
        ans = ans.pow(lex);
        cout << ans.val() << endl;
    }
    return 0;
}
