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

const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

vector<vi> g;
vector<vector<vi>> dp;
vi x;
int dfs(int v, int c, int val) {
    if (dp[v][c][val] != -1) return dp[v][c][val];
    int res = 0;
    for (int p : g[v]) {
        int val1 = dfs(p, c, c), val2 = dfs(p, 1-c, c);
        if (val1==INF && val2==INF) return (dp[v][c][val] = INF);
        else if (val1==INF || val2==INF) res += min(val1, val2);
        else res += max(val1, val2);
    }
    if (val==c) return (dp[v][c][val] = (res<=x[v]?x[v]:INF));
    else return (dp[v][c][val] = res);
}

int main(){
    int n;
    cin >> n;
    g = vector<vi>(n);
    rep1(i, n-1) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
    }
    x = vi(n);
    rep(i, n) cin >> x[i];
    dp = vector<vector<vi>>(n, vector<vi>(2, vi(2, -1)));
    if (dfs(0, 0, 0)!=x[0]) cout << NO << endl;
    else cout << YES << endl;
    return 0;
}
