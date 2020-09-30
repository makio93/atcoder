#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const string YES = "Yes";
const string NO = "No";

int main(){
    int n, d;
    cin >> n >> d;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vpii x2(n), y2(n);
    rep(i, n) {
        x2[i].first = x[i];
        y2[i].first = y[i];
        x2[i].second = y2[i].second = i;
    }
    VSORT(x2); VSORT(y2);
    vector<bool> f(n), g(n);
    rep(i, n) {
        bool res = true;
        if (i-1>=0) if (x2[i].first-x2[i-1].first < d) res = false;
        if (i+1<n) if (x2[i+1].first-x2[i].first < d) res = false;
        f[x2[i].second] = res;
    }
    rep(i, n) {
        bool res = true;
        if (i-1>=0) if (y2[i].first-y2[i-1].first < d) res = false;
        if (i+1<n) if (y2[i+1].first-y2[i].first < d) res = false;
        g[y2[i].second] = res;
    }
    two_sat ts(2*n);
    rep(i, n) {
        ts.add_clause(i, f[i], n+i, g[i]);
    }
    if (ts.satisfiable()) {
        auto res = ts.answer();
        vi ans;
        rep(i, sz(res)) {
            if (!res[i]) continue;
            if (i<n) ans.pb(x[i]);
            else ans.pb(y[i-n]);
        }
        cout << YES << endl;
        rep(i, sz(ans)) {
            cout << ans[i] << endl;
        }
    }
    else cout << NO << endl;
    return 0;
}
