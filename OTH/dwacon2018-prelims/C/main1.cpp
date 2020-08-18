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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const long long MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    int ka = 0, kb = 0;
    rep(i, n) ka += a[i];
    rep(i, m) kb += b[i];
    int ml = max(n, m), mk = max(ka, kb);
    vector<vll> dp(ml+2, vll(mk+2, 0)), sdp(ml+3, vll(mk+2, 0));
    dp[0][0] = dp[1][1] = 1;
    rep1(i, ml) rep1(j, mk) {
        if (j+i<=mk) dp[i][j+i] = (dp[i][j+i] + dp[i][j]) % MOD;
        dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
    }
    rep(j, mk+1) rep(i, ml+2) {
        sdp[i+1][j] = (dp[i][j] + sdp[i][j]) % MOD;
    }
    vi gla, glb;
    int cnta = 1, cntb = 1;
    rep(i, n) {
        if (i<n-1&&a[i]==a[i+1]) ++cnta;
        else {
            gla.pb(cnta);
            cnta = 1;
        }
    }
    rep(i, m) {
        if (i<m-1&&b[i]==b[i+1]) ++cntb;
        else {
            glb.pb(cntb);
            cntb = 1;
        }
    }
    int gna = sz(gla), gnb = sz(glb);
    vector<vll> dpa(gna+1, vll(kb+1, 0)), dpb(gnb+1, vll(ka+1, 0));
    dpa[0][0] = 1;
    rep(i, gna) rep(j, kb+1) {
        for (int k=0; k<=j; ++k) dpa[i+1][j] = (dpa[i+1][j] + (dpa[i][k] % MOD * sdp[gla[i]+1][j-k]) % MOD) % MOD;
    }
    dpb[0][0] = 1;
    rep(i, gnb) rep(j, ka+1) {
        for (int k=0; k<=j; ++k) dpb[i+1][j] = (dpb[i+1][j] + (dpb[i][k] % MOD * sdp[glb[i]+1][j-k]) % MOD) % MOD;
    }
    cout << (dpa[gna][kb] * dpb[gnb][ka] % MOD) << endl;
    return 0;
}
