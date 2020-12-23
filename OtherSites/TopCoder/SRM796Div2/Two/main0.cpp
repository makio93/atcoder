#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

ll comb(int a, int b) {
    if (b > a) return 0;
    if (a-b < b) b = a-b;
    ll res = 1;
    int r = a, t = 1;
    rep(i, b) {
        res *= r;
        res /= t;
        --r; ++t;
    }
    return res;
}

set<int> unused, order;
void calc(int p, ll step, int len, int n) {
    if (step==0 || len==0) return;
    if (step == 1) {
        auto itr = unused.begin();
        rep(i, len) {
            order.insert(*itr);
            ++itr;
        }
        unused.erase(unused.begin(), itr);
        return;
    }
    else if (len == 1) {
        auto itr = unused.begin();
        rep(i, step-1) ++itr;
        order.insert(*itr);
        ++itr;
        unused.erase(unused.begin(), itr);
        return;
    }
    else {
        int nnum = n-p - 1, nlen = len - 1, k = 0;
        ll sub = comb(nnum, nlen);
        while (step-sub > 0) {
            step -= sub;
            ++k;
            --nnum; ++p;
            sub = comb(nnum, nlen);
        }
        auto itr = unused.begin();
        rep(i, k) ++itr;
        order.insert(*itr);
        ++itr;
        unused.erase(unused.begin(), itr);
        calc(p+1, step, nlen, n);
    }
}

class ChristmasLightsFixing {
public:
    vi fixingTime(int N, ll step) {
        ll sub = 0;
        int len = 0;
        while (step-sub > 0) {
            step -= sub;
            ++len;
            sub = comb(N, len);
        }
        rep(i, N) unused.insert(i);
        calc(0, step, len, N);
        vi res;
        snuke(order, itr) res.pb(*itr);
        return res;
    }
};

int main(){
    int N;
    ll step;
    cin >> N >> step;
    ChristmasLightsFixing cl;
    auto res = cl.fixingTime(N, step);
    rep(i, sz(res)) printf("%d%c", res[i], (i<sz(res)-1?' ':'\n'));
    return 0;
}
