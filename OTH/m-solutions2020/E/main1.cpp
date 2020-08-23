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

int main(){
    int n;
    cin >> n;
    vi x(n), y(n), p(n);
    rep(i, n) cin >> x[i] >> y[i] >> p[i];
    vector<vll> xd(1<<n, vll(n)), yd(1<<n, vll(n));
    rep(i, 1<<n) {
        vll valx(n, INF), valy(n, INF);
        rep(k, n) {
            valx[k] = (ll)abs(x[k]) * p[k];
            valy[k] = (ll)abs(y[k]) * p[k];
        }
        rep(j, n) if ((i>>j)&1) {
            rep(k, n) {
                valx[k] = min(valx[k], (ll)abs(x[k]-x[j])*p[k]);
                valy[k] = min(valy[k], (ll)abs(y[k]-y[j])*p[k]);
            }
        }
        xd[i] = valx; yd[i] = valy;
    }
    vll ans(n+1, INF);
    int t = 1;
    rep(i, n) t *= 3;
    rep(i, t) {
        int t2 = i, xi = 0, yi = 0, bcnt = 0;
        rep(j, n) {
            if (t2%3==1) xi |= (1<<j);
            if (t2%3==2) yi |= (1<<j);
            if (t2%3!=0) ++bcnt;
            t2 /= 3;
        }
        ll sum = 0;
        rep(j, n) sum += min(xd[xi][j], yd[yi][j]);
        ans[bcnt] = min(ans[bcnt], sum);
    }
    rep(i, n+1) cout << ans[i] << endl;
    return 0;
}
