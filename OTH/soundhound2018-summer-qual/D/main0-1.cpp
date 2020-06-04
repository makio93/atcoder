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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s; --t;
    vector<vector<pair<int, pii>>> g(n);
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u; --v;
        g[u].emplace_back(v, pii(a, b));
        g[v].emplace_back(u, pii(a, b));
    }
    rep(i, n) {
        priority_queue<tuple<bool, ll, int>, vector<tuple<bool, ll, int>>, less<tuple<bool, ll, int>>> q;
        vll b(n, -1), f(n, -1);
        q.emplace(false, (ll)(1e15), s);
        b[s] = (ll)(1e15);
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            bool stat = get<0>(p);
            int vert = get<2>(p);
            ll money = get<1>(p);
            for (auto to : g[vert]) {
                if (!stat) {
                    if (b[to.first] < money-to.second.first) {
                        q.emplace(false, money-to.second.first, to.first);
                        b[to.first] = money-to.second.first;
                    }
                    if (vert>=i && f[to.first]<money-to.second.second) {
                        q.emplace(true, money-to.second.second, to.first);
                        f[to.first] = money-to.second.second;
                    }
                }
                else {
                    if (f[to.first] < money-to.second.second) {
                        q.emplace(true, money-to.second.second, to.first);
                        f[to.first] = money-to.second.second;
                    }
                }
            }
        }
        cout << f[t] << endl;
    }
    return 0;
}
