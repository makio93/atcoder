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

int n;
vector<bool> vis;
vector<vector<bool>> g;
void dfs(int x) {
    vis[x] = true;
    rep(i, n) if (g[x][i] && !vis[i]) dfs(i);
}

int main(){
    int m;
    cin >> n >> m;
    g = vector<vector<bool>>(n, vector<bool>(n));
    vi a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    rep(i, m) g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    int ans = 0;
    rep(i, m) {
        g[a[i]][b[i]] = g[b[i]][a[i]] = false;
        vis = vector<bool>(n);
        dfs(0);
        bool brd = false;
        rep(i, n) if (!vis[i]) brd = true;
        if (brd) ++ans;
        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }
    cout << ans << endl;
    return 0;
}
