#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// 本番中に作成途中だったコードに加筆して自力で完成させたもの　自力AC完了

int n, m;
vector<vpii> g;
vi val;
bool ans = true;
void dfs(int v, int p=-1) {
    if (!ans) return;
    int cval = 1;
    for (auto pr : g[v]) {
        int to = pr.first, eval = pr.second;
        if (val[to]==0 || to!=p) continue;
        if (val[to] != eval) cval = eval;
        else if (cval == eval) ++cval;
        if (cval > n) {
            ans = false;
            return;
        }
        break;
    }
    val[v] = cval;
    for (auto pr : g[v]) {
        int to = pr.first, toval = val[to];
        if (toval != 0) continue;
        dfs(to, v);
        if (!ans) return;
    }
}

int main(){
    cin >> n >> m;
    g = vector<vpii>(n);
    val = vi(n);
    rep(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    dfs(0);
    if (ans) {
        rep(i, n) cout << val[i] << endl;
    }
    else cout << "No" << endl;
    return 0;
}
