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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, l, t;
    cin >> n >> l >> t;
    vi x(n), w(n);
    rep(i, n) cin >> x[i] >> w[i];
    vpii y(n);
    rep(i, n) {
        int s = (w[i]==1?1:-1);
        y[i].first = (x[i] + s * (t % l)) % l;
        if (y[i].first<0) y[i].first = (l+y[i].first)%l;
        y[i].second = w[i];
    }
    vi rev;
    rep(i, n) if (w[0] != w[i]) rev.pb(x[i]);
    ll cnt = (ll)(sz(rev)) * (t / l) * 2;
    int x0 = (w[0]==1?x[0]:x[0]+l);
    for (int val : rev) {
        int dis = (w[0]==1?val-x0:x0-val);
        if (dis<=(t%l)*2) ++cnt;
        if ((ll)dis+l<=(ll)(t%l)*2) ++cnt;
    }
    int i2 = (w[0]==1?cnt%n:(n+(-cnt)%n)%n);
    int y0 = y[0].first;
    rep(i, n) y[i].second *= -1;
    VSORT(y);
    rep(i, n) y[i].second *= -1;
    int y0i = 0;
    while (y[y0i].first!=y0||y[y0i].second!=w[0]) ++y0i;
    vi ans(n);
    rep(i, n) ans[(i2+i)%n] = y[(y0i+i)%n].first;
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
