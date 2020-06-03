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

// auto mod int
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    // if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main(){
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) {
        int pi;
        cin >> pi;
        if (pi != -1) --pi;
        p[i] = pi;
    }
    UnionFind uf(n);
    rep(i, n) {
        if (p[i] != -1) uf.unite(p[i], i);
    }
    vi si;
    rep(i, n) {
        if (p[i] == -1) si.pb(i);
    }
    int k = sz(si);
    vi s;
    int rs = 0;
    rep(i, n) {
        if (uf.d[i] >= 0) continue;
        if (find(all(si), i) != si.end()) s.pb(uf.size(i));
        else ++rs; 
    }
    mint a(n);
    a *= mint(n-1).pow(k);
    vector<vector<mint>> dp(k+1, vector<mint>(k+1, 0));
    dp[0] = vector<mint>(k+1, 1);
    rep1(i, k) rep1(j, k) {
        dp[i][j] = dp[i][j-1];
        dp[i][j] += dp[i-1][j-1] * s[j-1];
    }
    rep1(j, k) dp[1][j] = dp[1][j-1] + s[j-1] - 1;
    mint b(0), fac(1);
    rep1(i, k) {
        if (i > 1) fac *= (i-1);
        b += dp[i][k] * fac * mint(n-1).pow(k-i);
    }
    b += mint(n-1).pow(k) * rs;
    cout << a - b << endl;
    return 0;
}
