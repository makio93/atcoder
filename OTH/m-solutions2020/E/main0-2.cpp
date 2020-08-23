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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    vector<pair<pii, int>> x(n), y(n);
    vi p(n);
    rep(i, n) {
        cin >> x[i].first.first >> y[i].first.first >> p[i];
        x[i].first.second = p[i]; y[i].first.second = p[i];
        x[i].second = i; y[i].second = i;
    }
    VSORT(x); VSORT(y);
    vpii xyi(n);
    rep(i, n) {
        xyi[x[i].second].first = i;
        xyi[y[i].second].second = i;
    }
    vll ans(n+1, INF);
    int t = 1;
    rep(i, n) t *= 3;
    rep(i, t) {
        int t2 = i, fcnt = 0;
        vi xlis(1, 0), ylis(1, 0);
        rep(j, n) {
            if (t2%3==1) {
                xlis.pb(x[xyi[j].first].first.first);
                ++fcnt;
            }
            if (t2%3==2) {
                ylis.pb(y[xyi[j].second].first.first);
                ++fcnt;
            }
            t2 /= 3;
        }
        VSORT(xlis); VSORT(ylis);
        vll mn(n, INF);
        int xi = 1, yi = 1;
        rep(j, n) {
            while (xi+1<sz(xlis)&&x[j].first.first>=xlis[xi]) ++xi;
            mn[x[j].second] = min(mn[x[j].second], llabs((x[j].first.first-xlis[xi-1]))*(ll)(x[j].first.second));
            mn[x[j].second] = min(mn[x[j].second], llabs((x[j].first.first-xlis[xi]))*(ll)(x[j].first.second));
        }
        rep(j, n) {
            while (yi+1<sz(ylis)&&y[j].first.first>=ylis[yi]) ++yi;
            mn[y[j].second] = min(mn[y[j].second], llabs((y[j].first.first-ylis[yi-1]))*(ll)(y[j].first.second));
            mn[y[j].second] = min(mn[y[j].second], llabs((y[j].first.first-ylis[yi]))*(ll)(y[j].first.second));
        }
        ll sum = 0;
        rep(i, n) sum += mn[i];
        ans[fcnt] = min(ans[fcnt], sum);
    }
    rep(i, n+1) cout << ans[i] << endl;
    return 0;
}
