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

struct S {
    int zero, one;
    ll val;
    S(int zero=0, int one=0, ll val=0) : zero(zero), one(one), val(val) {}
};

S op(S a, S b) { return S(a.zero+b.zero, a.one+b.one, a.val+b.val+(ll)a.one*b.zero); }
S e() { return S(0, 0, 0); }
S mapping(bool f, S x) {
    if (f) {
        return S(x.one, x.zero, (ll)x.zero*x.one-x.val);
    }
    else return x;
}
bool composition(bool f, bool g) { return (f xor g); }
bool id() { return false; }

int main(){
    int n, q;
    cin >> n >> q;
    vector<S> a(n);
    rep(i, n) {
        int ai;
        cin >> ai;
        a[i] = S((int)(ai==0), (int)(ai==1), 0);
    }
    lazy_segtree<S, op, e, bool, mapping, composition, id> ls(a);
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            ls.apply(l, r, true);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << (ls.prod(l, r).val) << endl;
        }
    }
    return 0;
}
