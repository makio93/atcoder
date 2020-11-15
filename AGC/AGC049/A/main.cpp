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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

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

vector<vi> rg;
vector<set<int>> ls;
vector<bool> visited;
void dfs(int b, int v, int p=-1) {
    visited[v] = true;
    if (b != v) ls[b].insert(v);
    for (int to : rg[v]) {
        if (to == p) continue;
        if (visited[to]) continue;
        dfs(b, to, v);
    }
}

double combination(int a, int b) {
    if (a < b) return 0.0;
    double val = 1.0;
    if (a-b < b) b = a-b;
    for (int i=0; i<b; ++i) {
        val *= (a-i);
        val /= (i+1);
    }
    return val;
}

int main(){
    int n;
    cin >> n;
    vs s(n);
    rep(i, n) cin >> s[i];
    rg = vector<vi>(n);
    rep(i, n) rep(j, n) {
        if (s[i][j] == '0') continue;
        rg[j].pb(i);
    }
    ls = vector<set<int>>(n);
    rep(i, n) {
        visited = vector<bool>(n, false);
        dfs(i, i);
    }
    vector<vector<double>> cost(n, vector<double>(n));
    double ans = 0.0;
    rep(i, n) rep(j, n) {
        cost[i][j] += combination((n-j-1), (int)(sz(ls[i])));
        rep1(k, sz(ls[i])) cost[i][j] *= k;
        rep1(k, ((n-1)-sz(ls[i]))) cost[i][j] *= k;
        ans += cost[i][j];
    }
    rep1(i, n) ans /= i;
    printf("%.15f\n", ans);
    return 0;
}
