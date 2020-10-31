#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const long long mod = 998244353;
using mint = modint998244353;

// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

int main(){
    int n, kval;
    cin >> n >> kval;
    vector<vi> a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    dsu h(n), w(n);
    rep(i, n) for (int j=i+1; j<n; ++j) {
        bool ok = true;
        rep(k, n) if (a[i][k]+a[j][k] > kval) ok = false;
        if (ok) h.merge(i, j);
    }
    rep(i, n) for (int j=i+1; j<n; ++j) {
        bool ok = true;
        rep(k, n) if (a[k][i]+a[k][j] > kval) ok = false;
        if (ok) w.merge(i, j);
    }
    auto hg = h.groups(), wg = w.groups();
    combination cb(n);
    mint ans = 1;
    rep(i, sz(hg)) {
        ans *= cb.fact[sz(hg[i])];
    }
    rep(i, sz(wg)) {
        ans *= cb.fact[sz(wg[i])];
    }
    cout << ans.val() << endl;
    return 0;
}
