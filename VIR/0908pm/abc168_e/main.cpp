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

const long long mod = 1000000007;
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

// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < mod);
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
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<pll> ab, ab2;
    int zero = 0;
    rep(i, n) {
        if (a[i]==0 && b[i]==0) {
            ++zero;
            continue;
        }
        ab.emplace_back(a[i], b[i]);
        if (ab.back().first<0 || (ab.back().first==0&&ab.back().second<0)) {
            ab.back().first *= -1; ab.back().second *= -1;
        }
        ll div = gcd(llabs(ab.back().first), llabs(ab.back().second));
        ab.back().first /= div; ab.back().second /= div;
    }
    rep(i, sz(ab)) {
        pll val = ab[i];
        val.second *= -1;
        swap(val.first, val.second);
        if (val.first<0 || (val.first==0&&val.second<0)) {
            val.first *= -1; val.second *= -1;
        }
        ab2.pb(val);
        ll div = gcd(llabs(ab2.back().first), llabs(ab2.back().second));
        ab2.back().first /= div; ab2.back().second /= div;
    }
    map<pll, int> mp1, mp2;
    rep(i, sz(ab)) mp1[ab[i]]++;
    rep(i, sz(ab2)) mp2[ab2[i]]++;
    combination cb(n);
    mint bad = 0;
    for (auto p : mp1) {
        pll val = p.first; int num = p.second;
        if (mp2[val] == 0) continue;
        ll val2 = mp2[val];
        bad += (mint(2).pow(num)-1) * (mint(2).pow(val2)-1) * mint(2).pow(n-zero-num-val2) / 2;
    }
    if (zero > 0) bad += (mint)(n-zero) * zero + mint(2).pow(zero) - 1;
    mint ans = mint(2).pow(n) - 1 - bad;
    cout << ans << endl;
    return 0;
}
