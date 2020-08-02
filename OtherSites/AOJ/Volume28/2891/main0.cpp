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

vector<vi> g;
vector<bool> seen, finished;
stack<int> hist;
int pos = -1;
void dfs(int v, int p) {
    seen[v] = true;
    hist.push(v);
    for (int t : g[v]) {
        if (t == p) continue;
        if (finished[t]) continue;
        if (seen[t]) {
            pos = t;
            return;
        }
        dfs(t, v);
        if (pos != -1) return;
    }
    hist.pop();
    finished[v] = true;
}

int main(){
    int n;
    cin >> n;
    g = vector<vi>(n);
    rep(i, n) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    seen = vector<bool>(n);
    finished = vector<bool>(n);
    dfs(0, -1);
    set<int> cycle;
    while (!hist.empty()) {
        int p = hist.top();
        hist.pop();
        cycle.insert(p);
        if (p == pos) break;
    }
    int q;
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (cycle.count(a) && cycle.count(b)) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
}