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

int my_binary_search(vi& pp, int v) {
    int l = 0, r = pp.size();
    while (r - l > 0) {
        int c = (r + l) / 2;
        if (pp[c] == v) return c;
        if (pp[c] < v) l = c + 1;
        else r = c;
    }
    return r - 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vi p(n+1);
    rep1(i, n) cin >> p[i];
    vi pp((n+1)*(n+1));
    rep(i, n+1) rep(j, n+1) pp[i*(n+1)+j] = p[i] + p[j];
    sort(all(pp));
    int mx = 0;
    rep(a, n+1) rep(b, n+1) {
        int s = m - p[a] - p[b];
        if (s < 0) continue;
        int d = my_binary_search(pp, s);
        mx = max(mx, p[a] + p[b] + pp[d]);
    }
    cout << mx << endl;
    return 0;
}
