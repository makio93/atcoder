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

int main(){
    int n, k;
    cin >> n >> k;
    vector<vi> a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    mcf_graph<ll, int> g(n*n+2*n+2);
    rep(i, n) rep(j, n) g.add_edge(n*n+2*n, i*n+j, a[i][j], 1);
    rep(i, n) rep(j, n) g.add_edge(i*n+j, n*n+i, INF2, 0);
    rep(j, n) rep(i, n) g.add_edge(i*n+j, n*n+n+j, INF2, 0);
    rep(i, 2*n) g.add_edge(n*n+i, n*n+2*n+1, INF2, 0);
    auto g2 = g;
    auto res = g.slope(n*n+2*n, n*n+2*n+1);
    ll val = 0;
    for (auto p : res) {
        if (p.second <= 2*n*k) val = max(val, p.first);
    }
    g2.flow(n*n+2*n, n*n+2*n+1, val);
    cout << val << endl;
    auto lis = g2.edges();
    vs ans(n, string(n, '.'));
    rep(i, sz(lis)) {
        if (lis[i].from != n*n+2*n) continue;
        if (lis[i].to >= n*n) continue;
        if (lis[i].flow <= 0) continue;
        int i2 = lis[i].to / n, j2 = lis[i].to % n;
        ans[i2][j2] = 'X';
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
