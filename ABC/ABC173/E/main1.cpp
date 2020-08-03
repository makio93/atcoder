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

int main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    int npos = 0;
    rep(i, n) if (a[i] >= 0) ++npos;
    int nneg = n - npos;
    bool ok = false;
    if (npos > 0) {
        if (k==n) ok = (nneg%2==0);
        else ok = true;
    }
    else ok = (k%2==0);
    mint ans = 1;
    if (ok) {
        vi pos, neg;
        rep(i, n) {
            if (a[i] >= 0) pos.pb(a[i]);
            else neg.pb(a[i]);
        }
        VSORT(neg);
        if (k%2==1) {
            VSORT(pos);
            ans *= pos.back(); pos.pop_back();
            reverse(all(pos));
        }
        else RSORT(pos);
        vll x;
        for (int i=0; i+1<sz(pos); i+=2) x.pb((ll)(pos[i])*pos[i+1]);
        for (int i=0; i+1<sz(neg); i+=2) x.pb((ll)(neg[i])*neg[i+1]);
        RSORT(x);
        rep(i, k/2) ans *= x[i];
    }
    else {
        RSORT(a);
        rep(i, k) ans *= a[i];
    }
    cout << ans << endl;
    return 0;
}
