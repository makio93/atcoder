#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

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

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    ll c;
    cin >> n >> c;
    vll x(n), x2;
    vi v(n), v2;
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> v[i];
    x2.pb(0);
    rep(i, n) x2.pb(x[i]);
    rep(i, n) v2.pb(v[i]);
    x2.pb(c); v2.pb(0);
    rep(i, n) x2.pb(c+x[i]);
    rep(i, n) v2.pb(v[i]);
    vll sum(2*n+2);
    rep(i, 2*n+1) sum[i+1] = sum[i] + (v2[i] - (x2[i+1]-x2[i]));
    ll ansr = -INF, ansl = -INF;
    int r = -1, l = -1;
    for (int i=n; i<2*n+1; ++i) {
        if (ansr < sum[i+1]-sum[n]) {
            ansr = sum[i+1]-sum[n];
            r = i;
        }
    }
    for (int i=n; i>=0; --i) {
        if (ansl < sum[n+1]-sum[i]) {
            ansl = sum[n+1]-sum[i];
            if (i < r-n) continue;
            l = i;
        }
    }
    ll ans = max({ansl, ansr, (sum[r+1]-sum[l])-(x2[r+1]-x2[n+1]), (sum[r+1]-sum[l])-(x2[n+1]-x2[l+1])});
    cout << ans << endl;
    return 0;
}
