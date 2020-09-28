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

// 解説放送分

using mint = modint998244353;

const mint inv9 = mint(1) / mint(9);

struct S {
    mint x, w;
    S(mint x=0, mint w=1) : x(x), w(w) {}
};

S op(S a, S b) { return S(a.x*b.w+b.x, a.w*b.w); }

S e() { return S(0, 1); }

S mapping(int f, S s) {
    if (f == 0) return s;
    else return S((s.w-1)*inv9*f, s.w);
}

int composition(int g, int f) {
    if (g == 0) return f;
    else return g;
}

int id() { return 0; }

int main(){
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, op, e, int, mapping, composition, id> seg(n);
    rep(i, n) seg.set(i, S(1, 10));
    rep(i, q) {
        int l, r, d;
        cin >> l >> r >> d;
        --l;
        seg.apply(l, r, d);
        cout << seg.all_prod().x.val() << endl;
    }
    return 0;
}
