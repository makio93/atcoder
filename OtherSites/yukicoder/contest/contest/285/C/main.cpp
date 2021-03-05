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

const ll mod = (ll)(1e9)+7;

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
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

const v(v(int)) add = { {0,0}, {0,0}, {1,0}, {0,0}, {2,0}, {0,1}, {1,0}, {0,0}, {3,0}, {0,0} };

int main(){
    string n;
    cin >> n;
    int len = sz(n);
    v(v(v(v(mint)))) dp(len, v(v(v(mint)))(2, v(v(mint))(3, v(mint)(3))));
    rep(i, 10) if (i != 0) {
        if (i < (int)(n.front()-'0')) {
            int k0 = min(2, add[i][0]), k1 = min(2, add[i][1]);
            dp.front()[0][k0][k1] += 1;
        }
        else if (i == (int)(n.front()-'0')) {
            int k0 = min(2, add[i][0]), k1 = min(2, add[i][1]);
            dp.front()[1][k0][k1] += 1;
        }
        else break;
    }
    rep2(i, 1, len-1) {
        rep(i2, 10) if (i2 != 0) {
            int k0 = min(2, add[i2][0]), k1 = min(2, add[i2][1]);
            dp[i][0][k0][k1] += 1;
        }
        rep(i2, 10) if (i2 != 0) {
            rep(j0, 3) rep(j1, 3) {
                int k0 = min(2, j0+add[i2][0]), k1 = min(2, j1+add[i2][1]);
                dp[i][0][k0][k1] += dp[i-1][0][j0][j1];
                if (i2 < (int)(n[i]-'0')) dp[i][0][k0][k1] += dp[i-1][1][j0][j1];
                if (i2 == (int)(n[i]-'0')) dp[i][1][k0][k1] += dp[i-1][1][j0][j1];
            }
        }
    }
    mint ans = dp.back()[0][2][2] + dp.back()[1][2][2];
    cout << ans << endl;
    return 0;
}
