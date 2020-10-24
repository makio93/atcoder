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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

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

// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<vector<mint>> psum(k+1, vector<mint>(n, 1));
    vector<vector<mint>> ksum(k, vector<mint>(n+1, 0));
    rep1(i, k) {
        repr(j, n) {
            psum[i][j] *= psum[i-1][j] * a[j];
            if (j+1<n) psum[i][j] += psum[i][j+1];
        }
    }
    combination cb(k);
    rep1(i, k) {
        ksum[i][n-1] = psum[i][n-1];
        repr(j, n-1) {
            ksum[i][j] = psum[i][j] + 
        }
    }
    return 0;
}
