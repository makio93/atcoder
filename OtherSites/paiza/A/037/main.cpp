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

#define INF (1e19)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct Frac {
    ull num, den;
    Frac(ull n=0, ull d=0) : num(n), den(d) {}
};
vector<vector<pair<int, Frac>>> g;
vector<Frac> f;
void dfs(int v, int p, Frac r) {
    if (f[v].num!=0) return;
    f[v] = {1, 1};
    f[v].num = f[p].num * r.num;
    f[v].den = f[p].den * r.den;
    for (auto t : g[v]) {
        if (t.first == p) continue;
        dfs(t.first, v, t.second);
    }
}

int main(){
    int n;
    cin >> n;
    g = vector<vector<pair<int, Frac>>>(n);
    rep(i, n-1) {
        int s, t, x;
        cin >> s >> t >> x;
        --s; --t;
        g[s].emplace_back(t, Frac(x, 1));
        g[t].emplace_back(s, Frac(1, x));
    }
    f = vector<Frac>(n);
    dfs(0, 0, Frac(1, 1));
    ull r1 = 1;
    rep(i, n) r1 = lcm(r1, f[i].den);
    rep(i, n) {
        ull r2 = r1 / f[i].den;
        f[i].num *= r2;
        f[i].den = 1;
    }
    pair<ull, int> mi = {INF, -1};
    rep(i, n) mi = min(mi, {f[i].num, i});
    ull r3 = mi.first;
    rep(i, n) {
        ull r4 = gcd(f[i].num, r3);
        f[i].num /= r4;
        f[i].den = r3 / r4;
        ull r5 = gcd(f[i].num, f[i].den);
        f[i].num /= r5; f[i].den /= r5;
    }
    rep(i, n) {
        if (f[i].den == 1) cout << f[i].num << endl;
        else printf("%llu/%llu\n", f[i].num, f[i].den);
    }
    return 0;
}
