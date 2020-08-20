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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const long long MOD = 1000000007;

// auto mod int
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
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

    // for prime MOD
    mint inv() const { return pow(MOD-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vpii a;
    int mt = m, d = 2;
    while (mt > 1) {
        if (mt%d==0) {
            if (!a.empty()&&a.back().first==d) a.back().second++;
            else a.emplace_back(d, 1);
            mt /= d;
        }
        else ++d;
    }
    int k = sz(a), ks = 0;
    rep(i, k) ks += a[i].second;
    vector<vector<vector<mint>>> dp(k+1, vector<vector<mint>>(ks+1));
    combination cb(n);
    rep1(i, k) dp[i][0] = vector<mint>(1, 0);
    dp[0][0] = vector<mint>(1, 0);
    rep(j, ks+1) dp[0][j] = vector<mint>(1, 0);
    rep1(i, k) rep1(j, ks) dp[i][j] = vector<mint>(a[i-1].second+1);
    dp[1][0][0] = 1;
    rep(i, k) rep1(i2, ks) {
        rep(j, a[i].second+1) {
            dp[i+1][i2][j] += dp[i][i2].back() * cb(j+i2-1, i2-1);
            if (i2-1>0) {
                if (j>0) dp[i+1][i2][j] += dp[i+1][i2-1][j-1] * max(0, i2-j+1);
            }
            else if (j>0) dp[i+1][i2][j] += dp[i+1][i2-1][0];
        }
    }
    mint ans = 0;
    rep1(i, min(ks, n)) ans += (mint(dp[k][i].back()) * cb(n, i));
    //rep1(i, ks) cout << dp[k][i].back() << endl;
    cout << ans << endl;
    return 0;
}
