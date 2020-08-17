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
    vector<vi> dist(n, vi(n, INF));
    queue<int> q;
    rep(i, n) {
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            int pd = dist[i][v];
            for (int t : g[v]) {
                if (dist[i][t] != INF) continue;
                q.push(t);
                dist[i][t] = pd+1;
            }
        }
    }
    vector<vpii> g2(n);
    rep(i, n) rep(j, n) {
        if (dist[i][j] > r[i]) continue;
        g2[i].emplace_back(j, c[i]);
    }
    priority_queue<pii, vpii, greater<pii>> q2;
    vi dist2(n, INF);
    q2.emplace(0, 0);
    dist2[0] = 0;
    while (!q2.empty()) {
        auto p = q2.top(); q2.pop();
        int pd = p.first, v = p.second;
        if (pd > dist2[v]) continue;
        for (auto t : g2[v]) {
            int nv = t.first, nd = pd + t.second;
            if (nd >= dist2[nv]) continue;
            q2.emplace(nd, nv);
            dist2[nv] = nd;
        }
    }
    cout << dist2[n-1] << endl;
    return 0;
}
