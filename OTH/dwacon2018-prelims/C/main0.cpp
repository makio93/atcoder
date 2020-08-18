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
    vi sca, scb;
    int cnt = 0;
    rep1(i, n-1) {
        ++cnt;
        if (a[i-1] != a[i]) {
            sca.pb(cnt);
            cnt = 0;
        }
    }
    sca.pb(cnt+1);
    cnt = 0;
    rep1(i, m-1) {
        ++cnt;
        if (b[i-1] != b[i]) {
            scb.pb(cnt);
            cnt = 0;
        }
    }
    scb.pb(cnt+1);
    int scamx = 0, scbmx = 0;
    int an = sz(sca), bn = sz(scb);
    rep(i, an) scamx = max(scamx, sca[i]);
    rep(i, bn) scbmx = max(scbmx, scb[i]);
    int suma = 0, sumb = 0;
    rep(i, n) suma += a[i];
    rep(i, m) sumb += b[i];
    vector<vll> subdpa(scamx+1, vll(sumb+1)), subdpb(scbmx+1, vll(suma+1));
    subdpa[0][0] = subdpb[0][0] = 1;
    rep1(i, scamx) rep(j, sumb+1) {
        if (j-i>=0) subdpa[i][j] = (subdpa[i][j-i] + subdpa[i-1][j]) % MOD;
        else subdpa[i][j] = subdpa[i-1][j];
    }
    rep1(i, scbmx) rep(j, suma+1) {
        if (j-i>=0) subdpb[i][j] = (subdpb[i][j-i] + subdpb[i-1][j]) % MOD;
        else subdpb[i][j] = subdpb[i-1][j];
    }
    vector<vll> dpa(an+1, vll(sumb+1)), dpb(bn+1, vll(suma+1));
    dpa[0][0] = dpb[0][0] = 1;
    rep1(i, an) rep(j, sumb+1) {
        if (sca[i-1] == 1) rep(k, j+1) dpa[i][j] = (dpa[i][j] + dpa[i-1][k]) % MOD;
        else rep(k, j+1) dpa[i][j] = (dpa[i][j] + dpa[i-1][k] * subdpa[sca[i-1]][j-k]) % MOD;
    }
    rep1(i, bn) rep(j, suma+1) {
        if (scb[i-1] == 1) rep(k, j+1) dpb[i][j] = (dpb[i][j] + dpb[i-1][k]) % MOD;
        else rep(k, j+1) dpb[i][j] = (dpb[i][j] + dpb[i-1][k] * subdpb[scb[i-1]][j-k]) % MOD;
    }
    ll ans = (dpa[an][sumb] * dpb[bn][suma]) % MOD;
    cout << ans << endl;
    return 0;
}
