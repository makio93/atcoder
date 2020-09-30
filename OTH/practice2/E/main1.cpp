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
    vector<vll> a(n, vll(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    mcf_graph<int, ll> g(2*n+2);
    int s = 2*n, t = 2*n+1;
    g.add_edge(s, t, n*k, INF);
    rep(i, n) g.add_edge(s, i, k, 0);
    rep(i, n) g.add_edge(n+i, t, k, 0);
    rep(i, n) rep(j, n) g.add_edge(i, n+j, 1, (ll)(INF)-a[i][j]);
    auto res = g.flow(s, t, n*k);
    cout << ((ll)n*k*(ll)INF-res.second) << endl;
    auto egs = g.edges();
    vs ans(n, string(n, '.'));
    rep(i, sz(egs)) {
        if (egs[i].from>=2*n || egs[i].to>=2*n) continue;
        if (egs[i].flow == 0) continue;
        ans[egs[i].from][egs[i].to-n] = 'X';
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
