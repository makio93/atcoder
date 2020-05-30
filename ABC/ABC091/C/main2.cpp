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

int n;
vector<vi> g;
vi match;
vector<bool> used;
bool dfs(int v) {
    used[v] = true;
    for (int i=0; i<sz(g[v]); ++i) {
        int u = g[v][i], w = match[u];
        if (w==-1 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    g = vector<vi>(n*2);
    match = vi(n*2, -1);
    vpii ab(n), cd(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    rep(i, n) cin >> cd[i].first >> cd[i].second;
    rep(i, n) rep(j, n) {
        if (ab[i].first >= cd[j].first) continue;
        if (ab[i].second >= cd[j].second) continue;
        g[i].pb(n+j);
        g[n+j].pb(i);
    }
    int ans = 0;
    rep(i, n) {
        if (match[n+i]==-1) {
            used = vector<bool>(n*2, false);
            if (dfs(n+i)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
