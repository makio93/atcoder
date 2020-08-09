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
    vi y(n);
    rep(i, n) {
        int s = (w[i]==w[0]?1:-1);
        y[i] = (x[i] + s * (t % l)) % l;
        if (y[i]<0) y[i] = (l-y[i])%l;
    }
    vi rev;
    rep1(i, n-1) if (w[0] != w[i]) rev.pb(x[i]);
    ll cnt = sz(rev) * (t / l) * 2;
    for (int val : rev) {
        if (val<x[0]) val+=l;
        int dis = val-x[0];
        if (dis/2.0<=t%l) ++cnt;
        if (dis/2.0+l/2.0<=t%l) ++cnt;
    }
    vi ans(n);
    rep(i, n) {
        int i2 = (w[0]==1?(i+cnt)%n:(n-(i-cnt)%n)%n);
        ans[i2] = y[i];
    }
    if (w[0] == 2) rep(i, n) ans[i] = (l-ans[i])%l;
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
