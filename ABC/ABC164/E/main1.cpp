#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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

struct Edge {
    int to, a, b;
    Edge(int to, int a, int b) : to(to), a(a), b(b) {}
};

struct Data {
    int v, s;
    ll x;
    Data(int v, int s, ll x) : v(v), s(s), x(x) {}
    bool operator<(const Data& a) const {
        return (x > a.x);
    }
};

const int a_max = 50;

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u; --v;
        g[u].emplace_back(v, a, b);
        g[v].emplace_back(u, a, b);
    }
    vi c(n), d(n);
    rep(i, n) {
        cin >> c[i] >> d[i];
    }
    const int sm = a_max * n;
    s = min(s, sm);
    vector<vll> dp(n, vll(sm+5, INF));
    priority_queue<Data> q;
    auto push = [&] (int v, int s, ll x) {
        if (s < 0) return;
        if (dp[v][s] <= x) return;
        dp[v][s] = x;
        q.emplace(v, s, x);
    };
    push(0, s, 0);
    while (!q.empty()) {
        Data p = q.top(); q.pop();
        int v = p.v, s = p.s;
        ll x = p.x;
        if (dp[v][s] != x) continue;
        {
            int ns = min(s+c[v], sm);
            push(v, ns, x+d[v]);
        }
        for (Edge e : g[v]) {
            push(e.to, s-e.a, x+e.b);
        }
    }
    rep1(i, n-1) {
        ll ans = INF;
        for (ll j : dp[i]) {
            ans = min(ans, j);
        }
        cout << ans << endl;
    }
    return 0;
}
