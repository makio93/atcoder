#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

// auto mod int
const ll mod = (ll)(1e9) + 7;
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
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int kmax, nmax;
v(v(bool)) visited;
v(v(mint)) memo;
mint dfs(int n, int k) {
    if (visited[n][k]) return memo[n][k];
    visited[n][k] = true;
    if (k <= 1) {
        if (n > 0) return (memo[n][k] = 0);
        else return (memo[n][k] = 1);
    }
    else {
        mint res = 1;
        if (k%2 == kmax%2) {
            rep(i, n) res += dfs(i, k-1);
        }
        else {
            rep(i, n) res += dfs(nmax-(i+1), k-1);
        }
        return (memo[n][k] = res);
    }
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, k;
        cin >> n >> k;
        kmax = k;
        nmax = n;
        if (kmax == 1) {
            cout << 1 << endl;
            continue;
        }
        if (nmax == 1) {
            cout << 2 << endl;
            continue;
        }
        visited = v(v(bool))(n+1, v(bool)(k+1));
        memo = v(v(mint))(n+1, v(mint)(k+1));
        mint res = dfs(n, k) + 1;
        cout << res.x << endl;
    }
    return 0;
}
