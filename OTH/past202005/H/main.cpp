#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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
    int n, l;
    cin >> n >> l;
    vector<bool> x(l+1);
    rep(i, n) {
        int xi;
        cin >> xi;
        x[xi] = true;
    }
    vi t(3);
    rep(i, 3) cin >> t[i];
    vll dp(l+1, INF);
    dp[0] = 0LL;
    rep1(i, l) {
        vll as;
        if (dp[i-1] != INF) {
            ll a = dp[i-1] + t[0];
            if (x[i]) a += t[2];
            as.pb(a);
        }
        if (i >= 2) {
            if (dp[i-2] != INF) {
                ll a = dp[i-2] + t[0] + t[1];
                if (x[i]) a += t[2];
                as.pb(a);
            }
        }
        if (i >= 4) {
            if (dp[i-4] != INF) {
                ll a = dp[i-4] + t[0] + t[1] * 3;
                if (x[i]) a += t[2];
                as.pb(a);
            }
        }
        for (ll val : as) dp[i] = min(dp[i], val);
    }
    ll ans = dp[l];
    rep1(i, 3) {
        int run = i * 2 - 1;
        ans = min(ans, dp[l-i]+t[0]/2+t[1]*run/2);
    }
    cout << ans << endl;
    return 0;
}
