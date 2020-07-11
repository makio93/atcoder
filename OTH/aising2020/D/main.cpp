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

ll mod = 1e9+7;

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
    int n;
    cin >> n;
    string x;
    cin >> x;
    bitset<200005> xn(x);
    int ori = xn.count();
    mod = ori + 1;
    mint num = 0;
    mint twop = 1;
    if (mod>1) {
        rep(i, n) {
            if (i!=0) twop *= 2;
            if (xn[i]==0) continue;
            num += twop;
        }
    }
    ll numx = num.x;
    mod = ori - 1;
    mint twom = 1, num2 = 0;
    ll num2x = 0;
    if (mod>1) {
        rep(i, n) {
            if (i!=0) twom *= 2;
            if (xn[i]==0) continue;
            num2 += twom;
        }
        num2x = num2.x;
    }
    repr(i, n) {
        bool pl = true;
        if (xn[i]==1) {
            mod = ori - 1;
            pl = false;
        }
        else mod = ori + 1;
        if (mod==0) {
            cout << 0 << endl;
            continue;
        }
        if (mod==1) {
            cout << 1 << endl;
            continue;
        }
        int cnt = 1;
        int xtmp;
        if (pl) {
            xtmp = (mint(numx) + mint(2).pow(i)).x;
        }
        else xtmp = (mint(num2x) - mint(2).pow(i)).x;
        while (xtmp != 0) {
            int j = __builtin_popcountll(xtmp);
            xtmp %= j;
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
