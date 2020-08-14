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

using Edge = pair<int, ll>;

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s; --t;
    vector<vector<Edge>> g1(n), g2(n);
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u; --v;
        g1[u].emplace_back(v, a);
        g1[v].emplace_back(u, a);
        g2[u].emplace_back(v, b);
        g2[v].emplace_back(u, b);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q1, q2;
    vll dist1(n, INF), dist2(n, INF);
    q1.emplace(0, s);
    dist1[s] = 0;
    while (!q1.empty()) {
        auto p = q1.top(); q1.pop();
        ll d = p.first; int v = p.second;
        if (d > dist1[v]) continue;
        for (auto to : g1[v]) {
            ll nd = d + to.second; int nv = to.first;
            if (nd >= dist1[nv]) continue;
            q1.emplace(nd, nv);
            dist1[nv] = nd;
        }
    }
    q2.emplace(0, t);
    dist2[t] = 0;
    while (!q2.empty()) {
        auto p = q2.top(); q2.pop();
        ll d = p.first; int v = p.second;
        if (d > dist2[v]) continue;
        for (auto to : g2[v]) {
            ll nd = d + to.second; int nv = to.first;
            if (nd >= dist2[nv]) continue;
            q2.emplace(nd, nv);
            dist2[nv] = nd;
        }
    }
    vll ans(n, 0);
    ll cost = INF;
    repr(i, n) {
        cost = min(cost, dist1[i]+dist2[i]);
        ans[i] = (ll)(1e15) - cost;
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
