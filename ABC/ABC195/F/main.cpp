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

int main(){
    ll a, b;
    cin >> a >> b;
    map<ll, map<ll, int>> prime;
    for (ll i=a; i<=b; ++i) {
        ll val = i;
        for (ll j=2; j*j<=val; ++j) {
            while (val%j == 0) {
                val /= j;
                prime[i][j]++;
            }
        }
        if (val > 1) prime[i][val]++;
    }
    ll out = 0;
    for (ll i=a; i<=b; ++i) {
        ll cnt = 0;
        for (ll j=i+1; j<=b; ++j) {
            bool ok = true;
            for (auto pi : prime[i]) {
                if (prime[j].find(pi.first) != prime[j].end()) ok = false;
            }
            if (!ok) ++cnt;
        }
        ll sum = (1LL<<(cnt+1));
        out += sum - (cnt+2);
    }
    ll ans = (1LL<<(b-a+1)) - out;
    cout << ans << endl;
    return 0;
}
