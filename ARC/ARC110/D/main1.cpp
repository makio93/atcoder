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

const ll mod = (ll)(1e9)+7;
using mint = modint1000000007;

ll comb(ll n, ll r) {
    if (r > n) return 0;
    if (n-r < r) r = n-r;
    if (r == 0) return 1;
    ll num = 1LL, den = 1LL;
    for (ll i=n; i>=n-r+1; --i) num = (num * i) % mod;
    for (ll i=1; i<=r; ++i) den = (den * i) % mod;
    return (mint(num) * mint(den).inv()).val();
}

int main(){
    ll n, m;
    cin >> n >> m;
    v(int) a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i];
    cout << comb(n+m, n+sum) << endl;
    return 0;
}
