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
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int p, q;
    cin >> p >> q;
    vi c(k);
    rep(i, k) {
        cin >> c[i];
        c[i]--;
    }
    vector<vi> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi dist(n, INF);
    dist[0] = dist[n-1] = 0;
    rep(i, k) {
        if (dist[c[i]] == 0) continue;
        queue<int> q1;
        q1.push(c[i]);
        dist[c[i]] = 0;
        while (!q1.empty()) {
            int v = q1.front(); q1.pop();
            int d = dist[v];
            if (d >= s) continue;
            for (int t : g[v]) {
                if (dist[t] <= d+1) continue;
                q1.push(t);
                dist[t] = d+1;
            }
        }
    }
    vi w(n);
    rep(i, n) {
        if (dist[i] == 0) w[i] = -1;
        else if (dist[i] <= s) w[i] = q;
        else w[i] = p;
    }
    w[0] = w[n-1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vll dist2(n, INF2);
    pq.emplace(0, 0);
    dist2[0] = 0;
    while (!pq.empty()) {
        auto p2 = pq.top(); pq.pop();
        ll d = p2.first;
        int v = p2.second;
        if (d > dist2[v]) continue;
        for (int t : g[v]) {
            if (w[t] == -1) continue;
            ll nd = d + w[t];
            if (nd >= dist2[t]) continue;
            pq.emplace(nd, t);
            dist2[t] = nd;
        }
    }
    cout << dist2[n-1] << endl;
    return 0;
}
