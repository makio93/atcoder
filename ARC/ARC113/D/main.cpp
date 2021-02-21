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

using mint = modint998244353;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    if (n==1 && m==1) {
        cout << k << endl;
    }
    else if (n==1) {
        mint ans = 0;
        rep2(i, 1, k) {
            mint sum = m;
            sum *= mint(k-i+1).pow(m-1);
            ans += sum;
        }
        cout << ans.val() << endl;
    }
    else if (m==1) {
        mint ans = 0;
        rep2(i, 1, k) {
            mint sum = n;
            sum *= mint(k-i+1).pow(n-1);
            ans += sum;
        }
        cout << ans.val() << endl;
    }
    else {
        mint ans = 0;
        rep2(i, 1, k) {
            mint sum = 1;
            sum *= mint(i).pow(n);
            sum *= mint(k-i+1).pow(m);
            ans += sum;
        }
        cout << ans.val() << endl;
    }
    return 0;
}
