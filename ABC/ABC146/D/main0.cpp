#include <bits/stdc++.h>
using namespace std;

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

vector<vpii> g;
vi ans;
void dfs(int v, int p, int c) {
    int nc = 1;
    for (auto tp : g[v]) {
        int t = tp.first, en = tp.second;
        if (t == p) continue;
        if (nc == c) ++nc;
        ans[en] = nc;
        dfs(t, v, nc);
        ++nc;
    }
}

int main(){
    int n;
    cin >> n;
    g = vector<vpii>(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    ans = vi(n-1);
    dfs(0, 0, 0);
    int cnum = 0;
    rep(i, n-1) cnum = max(cnum, ans[i]);
    cout << cnum << endl;
    rep(i, n-1) cout << ans[i] << endl;
    return 0;
}
