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

#define INF (1e15)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

vll calc(vpii a) {
    int ni = sz(a);
    VSORT(a);
    vector<vll> dp(ni+1, vll(ni+1, INF));
    dp[0][0] = 0;
    rep(l, ni) {
        for (int r=l+1; r<=ni; ++r) {
            ll now = INF;
            for (int k=l+1; k<=r; ++k) {
                ll sum = 0;
                for (int i=l+1; i<=r; ++i) sum += abs(a[i-1].first-a[k-1].first) * (ll)a[i-1].second;
                now = min(now, sum);
            }
            rep(j, ni) dp[r][j+1] = min(dp[r][j+1], dp[l][j]+now);
            for (int i=l+1; i<=r; ++i) now += abs(a[i-1].first) * (ll)a[i-1].second;
            rep(j, ni+1) dp[r][j] = min(dp[r][j], dp[l][j]+now);
        }
    }
    return dp[ni];
}

int main(){
    int n;
    cin >> n;
    vi x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];
    vll ans(n+1, INF);
    rep(i, 1<<n) {
        vpii xi, yi;
        rep(j, n) {
            if ((i>>j)&1) xi.emplace_back(x[j], p[j]);
            else yi.emplace_back(y[j], p[j]);
        }
        vll resx = calc(xi);
        vll resy = calc(yi);
        vll res(n+1, INF);
        rep(j1, sz(resx)) rep(j2, sz(resy)) {
            res[j1+j2] = min(res[j1+j2], resx[j1]+resy[j2]);
        }
        rep(j, n+1) ans[j] = min(ans[j], res[j]);
    }
    rep(i, n+1) cout << ans[i] << endl;
    return 0;
}
