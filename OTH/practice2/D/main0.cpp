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
    int n, m;
    cin >> n >> m;
    vs s(n);
    rep(i, n) cin >> s[i];
    mf_graph<int> g(n*m+2);
    for (int i=0; i<n; ++i) for (int j=i%2; j<m; j+=2) {
        if (i-1>=0) {
            if (s[i][j]=='.' && s[i-1][j]=='.') g.add_edge(i*m+j, (i-1)*m+j, 1);
        }
        if (i+1<n) {
            if (s[i][j]=='.' && s[i+1][j]=='.') g.add_edge(i*m+j, (i+1)*m+j, 1);
        }
        if (j-1>=0) {
            if (s[i][j]=='.' && s[i][j-1]=='.') g.add_edge(i*m+j, i*m+(j-1), 1);
        }
        if (j+1<m) {
            if (s[i][j]=='.' && s[i][j+1]=='.') g.add_edge(i*m+j, i*m+(j+1), 1);
        }
    }
    rep(i, n) rep(j, m) {
        if (s[i][j] == '#') continue;
        if ((i+j)%2==0) {
            g.add_edge(n*m, i*m+j, 1);
        }
        else {
            g.add_edge(i*m+j, n*m+1, 1);
        }
    }
    int fsum = g.flow(n*m, n*m+1);
    auto g2 = g.edges();
    vs ans = s;
    rep(i, sz(g2)) {
        if (g2[i].from>=n*m || g2[i].to>=n*m) break;
        if (g2[i].flow == 0) continue;
        int fi = g2[i].from/m, fj = g2[i].from%m, ti = g2[i].to/m, tj = g2[i].to%m;
        if (fi == ti) {
            if (fj > tj) swap(fj, tj);
            ans[fi][fj] = '>';
            ans[ti][tj] = '<';
        }
        else {
            if (fi > ti) swap(fi, ti);
            ans[fi][fj] = 'v';
            ans[ti][tj] = '^';
        }
    }
    cout << fsum << endl;
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
