#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

// const long long mod = 998244353;
using mint = modint998244353;

// combination mod prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        //assert(n < mod);
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

combination cb;
v(bool) mbit;
v(map<int,mint>) dp, cval;
int n, blen;
mint calc(int b, int d) {
    if (b == blen) {
        if (d == 0) return (mint)1;
        else return (mint)0;
    }
    if (dp[b].find(d) != dp[b].end()) return dp[b][d];
    if (d*2 > n) return (dp[b][d] = 0);
    if (d==0 && mbit[b]) return (dp[b][d] = 0);
    mint res = 0;
    rep2(i, 0, d) {
        int nd = (b+1<blen && mbit[b+1]) ? 1 : 0;
        res += calc(b+1, nd+i*2);
    }
    mint rval *= res * cb(n, d*2);
    return (dp[b][d] = res);
}

int main(){
    int m;
    cin >> n >> m;
    if (m%2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    cb = combination(n+5);
    mbit = v(bool);
    int tmval = m;
    while (tmval > 0) {
        if (tmval&1) mbit.pb(true);
        else mbit.pb(false);
        tmval >>= 1;
    }
    reverse(all(mbit));
    mbit.pop_back();
    int blen = sz(mbit);
    dp = v(map<int,mint>)(blen+1);
    cval = v(map<int,mint>)(blen+1);
    calc(0, 1);

    return 0;
}
