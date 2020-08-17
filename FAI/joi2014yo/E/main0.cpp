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

int main(){
    int n, k;
    cin >> n >> k;
    vi c(n), r(n);
    rep(i, n) cin >> c[i] >> r[i];
    vector<vi> g(n);
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> q;
    vector<vpii> dist(n, vpii(n, pii(INF, INF)));
    q.emplace(mp(c[0], 0), mp(0, 0));
    dist[0][0] = mp(c[0], 0);
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        auto pval = p.first, ppos = p.second;
        int d = pval.first, s = pval.second;
        int v = ppos.first, w = ppos.second;
        if (pval > dist[v][w]) continue;
        for (int t : g[v]) {
            if (r[w]-s>0) {
                if (dist[t][w] > mp(d, s+1)) {
                    q.emplace(mp(d, s+1), mp(t, w));
                    dist[t][w] = mp(d, s+1);
                }
            }
            if (dist[t][v] > mp(d+c[v], 1)) {
                q.emplace(mp(d+c[v], 1), mp(t, v));
                dist[t][v] = mp(d+c[v], 1);
            }
        }
    }
    int ans = INF;
    rep(i, n) ans = min(ans, dist[n-1][i].first);
    cout << ans << endl;
    return 0;
}
