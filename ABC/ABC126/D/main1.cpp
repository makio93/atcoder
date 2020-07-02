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

vector<vector<int>> to, cost;
vi ans;
void dfs(int v, int c = 0) {
    ans[v] = c;
    rep(i, sz(to[v])) {
        if (ans[to[v][i]] != -1) continue;
        int nc = (cost[v][i]%2==0 ? c : 1-c);
        dfs(to[v][i], nc);
    }
}

int main(){
    int n;
    cin >> n;
    to = vector<vector<int>>(n);
    cost = vector<vector<int>>(n);
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        to[u].pb(v);
        cost[u].pb(w);
        to[v].pb(u);
        cost[v].pb(w);
    }
    ans = vi(n, -1);
    dfs(0);
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
