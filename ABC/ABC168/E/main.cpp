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

int main(){
    int n;
    cin >> n;
    vpll ab(n), ab2(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        if (a < 0) {
            a *= -1; b *= -1;
        }
        ab[i].first = a; ab[i].second = b;
        if (b < 0) {
            a *= -1; b *= -1;
        }
        ab2[i].first = b; ab2[i].second = -a;
    }
    VSORT(ab); VSORT(ab2);
    auto itr1 = ab.begin(), itr2 = ab2.begin();
    while (*itr1==pll(0,0)) {
        ++itr1; ++itr2;
    }
    n -= itr1 - ab.begin();
    mint sub = mint(2).pow(n-2) - 1;
    mint ans = mint(2).pow(n) - 1;
    while (itr1!=ab.end()&&itr2!=ab2.end()) {
        while (itr1!=ab.end()&&itr2!=ab2.end()&&itr1!=itr2) {
            if (itr1->first < itr2->first) ++itr1;
            else if (itr1->first > itr2->first) ++itr2;
            else if (itr1->second < itr2->second) ++itr1;
            else ++itr2;
        }
        if (itr1==ab.end()||itr2==ab2.end()) break;
        ll cnt1 = 1, cnt2 = 1;
        pll tar = *itr1;
        ++itr1; ++itr2;
        while (*itr1 == tar) {
            ++cnt1;
            ++itr1;
        }
        while (*itr2 == tar) {
            ++cnt2;
            ++itr2;
        }
        ans -= sub * cnt1 * cnt2;
    }
    cout << ans << endl;
    return 0;
}
