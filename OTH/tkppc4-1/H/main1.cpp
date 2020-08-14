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

using Edge = pair<int, pii>;

int main(){
    int n, m;
    ll k;
    scanf("%d%d%lld", &n, &m, &k);
    vi t(n);
    for (int i=1; i<n-1; ++i) cin >> t[i];
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a; --b;
        g[a].emplace_back(b, pii(c, d));
        g[b].emplace_back(a, pii(c, d));
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vll dist(n, INF);
    q.emplace(0, 0);
    dist[0] = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        ll d = p.first; int v = p.second;
        if (d > dist[v]) continue;
        for (auto to : g[v]) {
            int nv = to.first, ci = to.second.first, di = to.second.second;
            ll nd = (d+(di-1))/di*di + ci + t[nv];
            if (dist[nv] <= nd) continue;
            q.emplace(nd, nv);
            dist[nv] = nd;
        }
    }
    if (dist[n-1] <= k) cout << dist[n-1] << endl;
    else cout << -1 << endl;
    return 0;
}
