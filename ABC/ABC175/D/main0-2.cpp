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
    int n, k;
    cin >> n >> k;
    vi p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vll c(n);
    rep(i, n) cin >> c[i];
    ll ans = -1e18;
    rep(i, n) {
        vll sum;
        vi pass(n, -1);
        sum.pb(0);
        int j = 0;
        pass[i] = j;
        int v = i;
        int rl = -1, rbi = -1;
        while (1) {
            ++j;
            v = p[v];
            ll val = sum.back();
            sum.pb(val+c[v]);
            if (pass[v] != -1) {
                rl = j - pass[v];
                rbi = pass[v];
                break;
            }
            pass[v] = j;
        }
        ll mx = -1e18;
        int rps = (k - rbi) / rl, rpr = (k - rbi) % rl;
        if (k <= rbi + rl) {
            rep1(i2, k) mx = max(mx, sum[i2]);
        }
        else if (sum.back()-sum[rbi]>=0) {
            rep1(i2, rbi) mx = max(mx, sum[i2]);
            rep1(i2, rpr) mx = max(mx, sum[rbi]+(sum.back()-sum[rbi])*rps+(sum[rbi+i2]-sum[rbi]));
            for (int i2=rpr+1; i2<=rl; ++i2) {
                mx = max(mx, sum[rbi]+(sum.back()-sum[rbi])*(rps-1)+(sum[rbi+i2]-sum[rbi]));
            }
        }
        else {
            rep1(i2, sz(sum)) mx = max(mx, sum[i2]);
        }
        ans = max(ans, mx);
    }
    cout << ans << endl;
    return 0;
}
