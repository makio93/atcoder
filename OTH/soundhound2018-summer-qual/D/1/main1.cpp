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

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s; --t;
    vector<vpii> ga(n), gb(n);
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u; --v;
        ga[u].emplace_back(v, a);
        ga[v].emplace_back(u, a);
        gb[u].emplace_back(v, b);
        gb[v].emplace_back(u, b);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> qa, qb;
    vll dista(n, INF), distb(n, INF);
    qa.emplace(0, s);
    dista[s] = 0;
    while (!qa.empty()) {
        int pos = qa.top().second; qa.pop();
        for (auto tos : ga[pos]) {
            int to = tos.first, cost = tos.second;
            if (dista[to] > dista[pos]+cost) {
                qa.emplace(dista[pos]+cost, to);
                dista[to] = dista[pos] + cost;
            }
        }
    }
    qb.emplace(0, t);
    distb[t] = 0;
    while (!qb.empty()) {
        int pos = qb.top().second; qb.pop();
        for (auto tos : gb[pos]) {
            int to = tos.first, cost = tos.second;
            if (distb[to] > distb[pos]+cost) {
                qb.emplace(distb[pos]+cost, to);
                distb[to] = distb[pos] + cost;
            }
        }
    }
    vll mns(n+1, INF);
    repr(i, n) mns[i] = min(mns[i+1], dista[i]+distb[i]);
    rep(i, n) cout << (ll)(1e15) - mns[i] << endl;
    return 0;
}
