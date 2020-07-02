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

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

vector<vector<Edge>> g;
vi color;
void dfs(int v, int c = 0) {
    color[v] = c;
    for (auto t : g[v]) {
        if (color[t.to] != -1) continue;
        int nc = (t.weight%2==0 ? c : 1-c);
        dfs(t.to, nc);
    }
}

int main(){
    int n;
    cin >> n;
    g = vector<vector<Edge>>(n);
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    color = vi(n, -1);
    dfs(0);
    rep(i, n) cout << color[i] << endl;
    return 0;
}
