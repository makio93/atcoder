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
    int k;
    cin >> k;
    vi a(k);
    rep(i, k) cin >> a[i];
    ll ansi = 2, ansx = 2;
    repr(i, k) {
        ansi = (ansi + a[i] - 1) / a[i] * a[i];
        ansx = ((ansx + a[i] - 1) / a[i] * a[i] + (a[i] - 1));
        if (i-1>=0) ansx = ansx / a[i-1] * a[i-1];
    }
    ll ansi2 = ansi, ansx2 = ansx;
    rep(i, k) {
        ansi2 -= ansi2 % a[i];
        ansx2 -= ansx2 % a[i];
    }
    if (ansi2!=2 && ansx2!=2) cout << -1 << endl;
    else {
        if (ansi2!=2) ansi = ansx;
        else if (ansx2!=2) ansx = ansi;
        printf("%lld %lld\n", ansi, ansx);
    }
    return 0;
}
