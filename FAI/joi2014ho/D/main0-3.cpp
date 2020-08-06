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

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vi h(n);
    rep(i, n) cin >> h[i];
    vector<vpii> g(n);
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        --a; --b;
        g[a].emplace_back(b, t);
        g[b].emplace_back(a, t);
    }
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> q;
    vector<ll> dist(n, INF);
    q.push({0, {0, x}});
    dist[0] = 0;
    ll ans = INF;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int now = p.second.first, xi = p.second.second;
        ll cost = p.first;
        if (cost != dist[now]) continue;
        for (auto to : g[now]) {
            int next = to.first, tcost = to.second;
            if (tcost>h[now]) continue;
            int mv = 0, nxi = 0;
            if (xi-tcost<0) mv = tcost - xi;
            else if (xi-tcost>h[next]) {
                mv = xi-tcost-h[next];
                nxi = h[next];
            }
            else nxi = xi - tcost;
            if (next==n-1) {
                ans = min(ans, cost+mv+tcost+abs(nxi-h[n-1]));
            }
            if (cost+mv+tcost >= dist[next]) continue;
            q.push({cost+mv+tcost, {next, nxi}});
            dist[next] = cost+mv+tcost;
        }
    }
    if (ans!=INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
