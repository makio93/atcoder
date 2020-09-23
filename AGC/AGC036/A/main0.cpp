#include <bits/stdc++.h>
using namespace std;

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

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    ll s;
    cin >> s;
    ll m = (s + (ll)(1e9)-1) / (ll)(1e9), n = (ll)1e9;
    if (m == 1) n = s / m;
    ll r = m*n - s;
    vpll ans(3);
    ans[1].first = m;
    ans[2].second = n;
    if (r == 0) {
        rep(i, 3) printf("%lld %lld%c", ans[i].first, ans[i].second, (i<2?' ':'\n'));
    }
    else {
        ll a = 0, b = 0;
        for (ll i=1; i<=n; ++i) {
            if (r%i==0 && r/i<=m) {
                a = i;
                b = r / i;
                break;
            }
        }
        ans[1].second = -a;
        ans[2].first = m - b;
        rep(i, 2) ans[i].second += a;
        rep(i, 3) printf("%lld %lld%c", ans[i].first, ans[i].second, (i<2?' ':'\n'));
    }
    return 0;
}
