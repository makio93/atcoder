#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

using mint = modint998244353;
struct S {
    mint val;
    int len;
    S(mint val=0, int len=0) : val(val), len(len) {}
};
using F = pair<mint, mint>;

S op(S a, S b) { return S(a.val+b.val, a.len+b.len); }
S e() { return S(0, 0); }
S mapping(F f, S x) { return S(x.val*f.first+x.len*f.second, x.len); }
F composition(F f, F g) { return F(f.first*g.first, f.first*g.second+f.second); }
F id() { return F(1, 0); }

int main(){
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> ls(n);
    rep(i, n) ls.set(i, S(mint(a[i]), 1));
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            ls.apply(l, r, F(b, c));
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << ls.prod(l, r).val.val() << endl;
        }
    }
    return 0;
}
