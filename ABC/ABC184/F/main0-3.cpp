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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    ll t;
    cin >> n >> t;
    vll a(n);
    rep(i, n) cin >> a[i];
    set<ll> l1, l2;
    l1.insert(0); l2.insert(0);
    int n1 = n/2, n2 = n-n1;
    rep(i, 1<<n1) {
        ll val = 0;
        bool ok = true;
        rep(j, n1) if ((i>>j)&1) {
            val += a[j];
            if (val > t) {
                ok = false;
                break;
            }
        }
        if (ok) l1.insert(val);
    }
    rep(i, 1<<n2) {
        ll val = 0;
        bool ok = true;
        rep(j, n2) if ((i>>j)&1) {
            val += a[n1+j];
            if (val > t) {
                ok = false;
                break;
            }
        }
        if (ok) l2.insert(val);
    }
    ll ans = 0;
    for (auto val : l1) {
        auto itr = l2.upper_bound(t-val);
        --itr;
        ans = max(ans, val+(*itr));
    }
    cout << ans << endl;
    return 0;
}
